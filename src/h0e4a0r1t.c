#include <furi.h>
#include <gui/gui.h>
#include <assets_icons.h> // 如果使用内置图标

static void render_callback(Canvas* canvas, void* ctx) {
    // 清除画布
    canvas_clear(canvas);
    
    // 绘制文本
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str_aligned(canvas, 10, 20, AlignLeft, AlignTop, "Hello, Flipper!");

    // 绘制图像
    int image_x = 10;
    int image_y = 50; // 根据需要调整位置
    canvas_draw_icon(canvas, image_x, image_y, &I_my_image); // 使用自定义图标
}

int my_app_main(void* p) {
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, render_callback, NULL);

    // 将视图端口添加到GUI并等待关闭信号
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);
    furi_thread_sleep(5000); // 运行5秒
    gui_remove_view_port(gui, view_port);

    view_port_free(view_port);
    furi_record_close(RECORD_GUI);
    return 0;
}