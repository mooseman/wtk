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

#include <wtk/wtk_label.h>

#include "_wtk_windows.h"
#include "_wtk_controls.h"

#include <wtk/wtk_mm.h>
#include <wtk/wtk_align.h>
#include <wtk/wtk_font.h>
#include <wtk/wtk_mouse.h>
#include <wtk/wtk_keyboard.h>

static LRESULT CALLBACK wtk_label_proc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

int WTK_API wtk_label_init()
{
    return TRUE;
}

struct wtk_label* WTK_API wtk_label_create( int x, int y, int width, int height, struct wtk_control* parent )
{
    struct wtk_label* label = NULL;
    HWND hWnd;

    WTK_ASSERT(parent);

    hWnd = CreateWindowExA(0, "STATIC", NULL, SS_LEFT | WS_VISIBLE | WS_CHILD, x, y, width, height, parent->hWnd, NULL, GetModuleHandle(0), 0);
    if( !hWnd ) return NULL;

    label = wtk_alloc(sizeof(struct wtk_label));
    memset((void*)label, 0, sizeof(struct wtk_label));
    label->control.type = WTK_CONTROL_TYPE(Label);
    label->control.hWnd = hWnd;
    label->control.font = wtk_font_default();
    label->text_align = WTK_ALIGN(Left);

    SetPropA(hWnd, "_wtk_old_proc", (HANDLE)SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)&wtk_label_proc));
    SetPropA(hWnd, "_wtk_ctrl_ptr", (HANDLE)label);
    PostMessage(hWnd, WM_SETFONT, (WPARAM)label->control.font->hFont, TRUE);
    PostMessage(hWnd, WM_USER + 0, 0, 0);
    return label;
}

static LRESULT CALLBACK wtk_label_proc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    struct wtk_control* control = (struct wtk_control*)GetPropA(hWnd, "_wtk_ctrl_ptr");
    struct wtk_label* label = (struct wtk_label*)control;
    if( !control ) return DefWindowProc(hWnd, uMsg, wParam, lParam);

    switch( uMsg ) {
        case WM_USER + 0: {
            if( control->on_create_callback ) control->on_create_callback(control, WTK_EVENT(OnCreate));
        } break;

        case WM_DESTROY: {
            if( control->on_destroy_callback ) control->on_destroy_callback(control, WTK_EVENT(OnDestroy));
            wtk_free(label);
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
            return CallWindowProc((WNDPROC)GetPropA(hWnd, "_wtk_old_proc"), hWnd, uMsg, wParam, lParam);
        } break;
    }

    return 0;
}