// =============================================================================
// This file is part of the Windowing Toolkit.
// Copyright (C) 2012 Michael Williams <devbug@bitbyte.ca>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// =============================================================================

#include <wtk/wtk_control.h>

#include "_wtk_windows.h"
#include "_wtk_controls.h"

#include <wtk/wtk_mm.h>
#include <wtk/wtk_font.h>
#include <wtk/wtk_mouse.h>
#include <wtk/wtk_keyboard.h>

#include <stdarg.h>

static LRESULT CALLBACK wtk_control_proc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

int WTK_API wtk_control_init()
{
    const WNDCLASSEX wcx = {
        sizeof(WNDCLASSEX),
        CS_HREDRAW | CS_VREDRAW,
        &wtk_control_proc,
        0, 0,
        GetModuleHandle(0),
        LoadIcon(NULL, IDI_APPLICATION),
        LoadCursor(NULL, IDC_ARROW),
        (HBRUSH)(COLOR_WINDOW + 1),
        NULL,
        "_wtk_control",
        LoadIcon(NULL, IDI_APPLICATION)
    };

    return RegisterClassEx(&wcx) ? TRUE : FALSE;
}

struct wtk_control* WTK_API wtk_control_create( int x, int y, unsigned int width, unsigned int height, struct wtk_control* parent )
{
    HWND hWnd;
    struct wtk_control* control;

    WTK_ASSERT(parent);

    hWnd = CreateWindowEx(0, "_wtk_control", NULL, WS_CHILD | WS_VISIBLE, x, y, width, height, parent->hWnd, NULL, GetModuleHandle(0), 0);
    if( !hWnd ) return NULL;

    control = wtk_alloc(sizeof(wtk_control));
    memset((void*)control, 0, sizeof(struct wtk_control));
    control->type = WTK_CONTROL_TYPE(Base);
    control->hWnd = hWnd;
    control->font = wtk_font_default();

    SetPropA(hWnd, "_wtk_ctrl_ptr", (HANDLE)control);
    PostMessage(hWnd, WM_SETFONT, (WPARAM)control->font->hFont, TRUE);
    PostMessage(hWnd, WM_USER + 1, 0, 0);
    return control;
}

extern void WTK_API wtk_menu_destroy( struct wtk_menu* menu );
extern void WTK_API wtk_menu_item_destroy( struct wtk_menu_item* menu_item );

void WTK_API wtk_control_destroy( struct wtk_control* control )
{
    WTK_ASSERT(control);

    // TODO: Add wtk_destroy_handlers.
    switch( control->type ) {
        case WTK_CONTROL_TYPE(Menu): {
            wtk_menu_destroy((struct wtk_menu*)control);
        } break;

        case WTK_CONTROL_TYPE(MenuItem): {
            wtk_menu_item_destroy((struct wtk_menu_item*)control);
        } break;

        default: {
            DestroyWindow(control->hWnd);
        } break;
    }
}

#include "_wtk_property_accessors.inl"

typedef struct {
    void (WTK_API *getter)( struct wtk_control*, va_list );
    void (WTK_API *setter)( struct wtk_control*, va_list );
} wtk_property_accessors;

static wtk_property_accessors _property_accessors[WTK_CONTROL_PROP_COUNT] = {
    { NULL, NULL },                                               // WTK_CONTROL_PROP_Invalid
    { &wtk_prop_user_ptr_getter, &wtk_prop_user_ptr_setter },     // WTK_CONTROL_PROP_UserPtr
    { &wtk_prop_position_getter, &wtk_prop_position_setter },     // WTK_CONTROL_PROP_Position
    { &wtk_prop_size_getter, &wtk_prop_size_setter },             // WTK_CONTROL_PROP_Size
    { &wtk_prop_font_getter, &wtk_prop_font_setter },             // WTK_CONTROL_PROP_Font
    { &wtk_prop_icon_getter, &wtk_prop_icon_setter },             // WTK_CONTROL_PROP_Icon
    { &wtk_prop_icons_getter, &wtk_prop_icons_setter },           // WTK_CONTROL_PROP_Icons
    { &wtk_prop_title_getter, &wtk_prop_title_setter },           // WTK_CONTROL_PROP_Title
    { &wtk_prop_menu_getter, &wtk_prop_menu_setter },             // WTK_CONTROL_PROP_Menu
    { &wtk_prop_text_getter, &wtk_prop_text_setter },             // WTK_CONTROL_PROP_Text
    { &wtk_prop_text_align_getter, &wtk_prop_text_align_setter }, // WTK_CONTROL_PROP_TextAlign
    { &wtk_prop_value_getter, &wtk_prop_value_setter },           // WTK_CONTROL_PROP_Value
    { &wtk_prop_column_getter, &wtk_prop_column_setter },         // WTK_CONTROL_PROP_Column
    { &wtk_prop_image_list_getter, &wtk_prop_image_list_setter }, // WTK_CONTROL_PROP_ImageList
};

void WTK_API wtk_control_get_property( struct wtk_control* control, wtk_control_property property, ... )
{
    va_list args;

    WTK_ASSERT(control);
    WTK_ASSERT(((property > WTK_CONTROL_PROP_Invalid) && (property < WTK_CONTROL_PROP_COUNT)));

    va_start(args, property);
    _property_accessors[property].getter(control, args);
    va_end(args);
}

void WTK_API wtk_control_set_property( struct wtk_control* control, wtk_control_property property, ... )
{
    va_list args;

    WTK_ASSERT(control);
    WTK_ASSERT(((property > WTK_CONTROL_PROP_Invalid) && (property < WTK_CONTROL_PROP_COUNT)));

    va_start(args, property);
    _property_accessors[property].setter(control, args);
    va_end(args);
}

#include "_wtk_child_property_accessors.inl"

typedef struct {
    void (WTK_API *getter)( struct wtk_control*, wtk_child, va_list );
    void (WTK_API *setter)( struct wtk_control*, wtk_child, va_list );
} wtk_child_property_accessors;

static wtk_child_property_accessors _child_property_accessors[WTK_CONTROL_PROP_COUNT] = {
    { NULL, NULL },                                                           // WTK_CONTROL_PROP_Invalid
    { &wtk_child_prop_user_ptr_getter, &wtk_child_prop_user_ptr_setter },     // WTK_CONTROL_PROP_UserPtr
    { &wtk_child_prop_default, &wtk_child_prop_default },                     // WTK_CONTROL_PROP_Position
    { &wtk_child_prop_default, &wtk_child_prop_default },                     // WTK_CONTROL_PROP_Size
    { &wtk_child_prop_default, &wtk_child_prop_default },                     // WTK_CONTROL_PROP_Font
    { &wtk_child_prop_icon_getter, &wtk_child_prop_icon_setter },             // WTK_CONTROL_PROP_Icon
    { &wtk_child_prop_default, &wtk_child_prop_default },                     // WTK_CONTROL_PROP_Icons
    { &wtk_child_prop_default, &wtk_child_prop_default },                     // WTK_CONTROL_PROP_Title
    { &wtk_child_prop_default, &wtk_child_prop_default },                     // WTK_CONTROL_PROP_Menu
    { &wtk_child_prop_text_getter, &wtk_child_prop_text_setter },             // WTK_CONTROL_PROP_Text
    { &wtk_child_prop_text_align_getter, &wtk_child_prop_text_align_setter }, // WTK_CONTROL_PROP_TextAlign
    { &wtk_child_prop_value_getter, &wtk_child_prop_value_setter },           // WTK_CONTROL_PROP_Value
    { &wtk_child_prop_column_getter, &wtk_child_prop_column_setter },         // WTK_CONTROL_PROP_Column
    { &wtk_child_prop_image_list_getter, &wtk_child_prop_image_list_setter }, // WTK_CONTROL_PROP_ImageList
};

void WTK_API wtk_control_get_child_property( struct wtk_control* control, wtk_control_property property, wtk_child child, ... )
{
    va_list args;

    WTK_ASSERT(control);
    WTK_ASSERT(((property > WTK_CONTROL_PROP_Invalid) && (property < WTK_CONTROL_PROP_COUNT)));

    va_start(args, child);
    _child_property_accessors[property].getter(control, child, args);
    va_end(args);
}

void WTK_API wtk_control_set_child_property( struct wtk_control* control, wtk_control_property property, wtk_child child, ... )
{
    va_list args;

    WTK_ASSERT(control);
    WTK_ASSERT(((property > WTK_CONTROL_PROP_Invalid) && (property < WTK_CONTROL_PROP_COUNT)));

    va_start(args, child);
    _child_property_accessors[property].setter(control, child, args);
    va_end(args);
}

#include "_wtk_event_accessors.inl"

typedef struct {
    void (WTK_API *setter)( struct wtk_control*, wtk_event_callback );
} wtk_event_accessors;

static wtk_event_accessors _event_accessors[WTK_EVENT_COUNT] = {
    { NULL },                                   // WTK_EVENT_Invalid
    { &wtk_event_on_create_setter },            // WTK_EVENT_OnCreate
    { &wtk_event_on_destroy_setter },           // WTK_EVENT_OnDestroy
    { &wtk_event_on_close_setter },             // WTK_EVENT_OnClose
    { &wtk_event_on_paint_setter },             // WTK_EVENT_OnPaint
    { &wtk_event_on_value_changed_setter },     // WTK_EVENT_OnValueChanged
    { &wtk_event_on_selection_changed_setter }, // WTK_EVENT_OnValueChanged
    { &wtk_event_on_pressed_setter },           // WTK_EVENT_OnPressed
    { &wtk_event_on_released_setter },          // WTK_EVENT_OnReleased
    { &wtk_event_on_clicked_setter },           // WTK_EVENT_OnClicked
    { &wtk_event_on_mouse_moved_setter },       // WTK_EVENT_OnMouseMoved
    { &wtk_event_on_mouse_scrolled_setter },    // WTK_EVENT_OnMouseScrolled
    { &wtk_event_on_key_pressed_setter },       // WTK_EVENT_OnKeyPressed
    { &wtk_event_on_key_released_setter },      // WTK_EVENT_OnKeyReleased
};

void WTK_API wtk_control_set_callback( struct wtk_control* control, wtk_event event, wtk_event_callback callback )
{
    WTK_ASSERT(control);
    WTK_ASSERT(((event > WTK_EVENT_Invalid) && (event < WTK_EVENT_COUNT)));
    _event_accessors[event].setter(control, callback);
}

static LRESULT CALLBACK wtk_control_proc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    struct wtk_control* control = (struct wtk_control*)GetPropA(hWnd, "_wtk_ctrl_ptr");
    if( !control ) return DefWindowProc(hWnd, uMsg, wParam, lParam);

    switch( uMsg ) {
        case WM_USER + 1: {
            if( control->on_create_callback ) control->on_create_callback(control, WTK_EVENT(OnCreate));
        } break;

        case WM_DESTROY: {
            if( control->on_destroy_callback ) control->on_destroy_callback(control, WTK_EVENT(OnDestroy));
            wtk_free(control);
        } break;

        case WM_LBUTTONDOWN: {
            if( control->on_pressed_callback ) control->on_pressed_callback(control, WTK_EVENT(OnPressed), WTK_MOUSE_BTN_LEFT, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            goto _default;
        } break;

        case WM_MBUTTONDOWN: {
            if( control->on_pressed_callback ) control->on_pressed_callback(control, WTK_EVENT(OnPressed), WTK_MOUSE_BTN_MIDDLE, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            goto _default;
        } break;

        case WM_RBUTTONDOWN: {
            if( control->on_pressed_callback ) control->on_pressed_callback(control, WTK_EVENT(OnPressed), WTK_MOUSE_BTN_RIGHT, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            goto _default;
        } break;

        case WM_LBUTTONUP: {
            if( control->on_released_callback ) control->on_released_callback(control, WTK_EVENT(OnReleased), WTK_MOUSE_BTN_LEFT, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            goto _default;
        } break;

        case WM_MBUTTONUP: {
            if( control->on_released_callback ) control->on_released_callback(control, WTK_EVENT(OnReleased), WTK_MOUSE_BTN_MIDDLE, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            goto _default;
        } break;

        case WM_RBUTTONUP: {
            if( control->on_released_callback ) control->on_released_callback(control, WTK_EVENT(OnReleased), WTK_MOUSE_BTN_RIGHT, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            goto _default;
        } break;

        default: {
        _default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        } break;
    }

    return 0;
}