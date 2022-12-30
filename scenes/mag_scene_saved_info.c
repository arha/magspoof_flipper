#include "../mag_i.h"

void mag_scene_saved_info_on_enter(void* context) {
    Mag* mag = context;
    Widget* widget = mag->widget;

    widget_add_string_element(
        widget,
        64,
        12,
        AlignCenter,
        AlignCenter,
        FontSecondary,
        furi_string_get_cstr(mag->mag_dev->dev_data));

    widget_add_button_element(widget, GuiButtonTypeLeft, "Back", mag_widget_callback, mag);

    view_dispatcher_switch_to_view(mag->view_dispatcher, MagViewWidget);
}

bool mag_scene_saved_info_on_event(void* context, SceneManagerEvent event) {
    Mag* mag = context;
    SceneManager* scene_manager = mag->scene_manager;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == GuiButtonTypeLeft) {
            consumed = true;

            scene_manager_previous_scene(scene_manager);
        }
    }

    return consumed;
}

void mag_scene_saved_info_on_exit(void* context) {
    Mag* mag = context;
    widget_reset(mag->widget);
}