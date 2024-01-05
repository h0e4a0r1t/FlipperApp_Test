#include <furi.h>
#include <gui/gui.h>
#include <assets_icons.h> // 如果使用内置图标
#include "main_icon.h"    // 自定义图标的头文件

static void render_callback(Canvas* canvas, void* ctx) {
    // 清除画布
    canvas_clear(canvas);
    
    // 绘制文本
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str_aligned(canvas, 10, 20, AlignLeft, AlignTop, "Hello, Flipper!");

    // 绘制图像
    int image_x = 10;
    int image_y = 50;
    // TODO: 使用合适的方式绘制 main_icon
    // 例如: canvas_draw_bitmap(canvas, image_x, image_y, main_icon);

    (void)ctx; // 忽略未使用的参数
}

int my_app_main(void* p) {
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, render_callback, NULL);

    // 将视图端口添加到GUI并等待关闭信号
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    // 使用正确的延时函数
    furi_delay_ms(5000); // 运行5秒

    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_record_close(RECORD_GUI);

    (void)p; // 忽略未使用的参数
    return 0;
}
