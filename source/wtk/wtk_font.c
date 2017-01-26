
// This is free and unencumbered software released into the public domain.  

// Anyone is free to copy, modify, publish, use, compile, sell, or           
// distribute this software, either in source code form or as a compiled    
// binary, for any purpose, commercial or non-commercial, and by any        
// means.                                                                   

// In jurisdictions that recognize copyright laws, the author or authors    
// of this software dedicate any and all copyright interest in the           
// software to the public domain. We make this dedication for the benefit    
// of the public at large and to the detriment of our heirs and              
// successors. We intend this dedication to be an overt act of               
// relinquishment in perpetuity of all present and future rights to this     
// software under copyright law.                                             

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF        
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR         
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR     
// OTHER DEALINGS IN THE SOFTWARE.                                           

// For more information, please refer to <http://unlicense.org/>             


#include <wtk/wtk_font.h>

#include "_wtk_windows.h"
#include "_wtk_font.h"

#include <wtk/wtk_mm.h>

#include <string.h>

struct wtk_font* WTK_API wtk_font_create( const char* font_family, unsigned int font_size, unsigned int font_style )
{
    LOGFONT lf;
    HFONT hFont;
    struct wtk_font* font;   

    GetObjectA(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
    hFont = CreateFontA(font_size,
                        0,
                        lf.lfEscapement,
                        lf.lfOrientation,
                        (font_style & WTK_FONT_STYLE_BOLD) ? FW_BOLD : FW_NORMAL,
                        (font_style & WTK_FONT_STYLE_ITALIC) == WTK_FONT_STYLE_ITALIC,
                        (font_style & WTK_FONT_STYLE_UNDERLINE) == WTK_FONT_STYLE_UNDERLINE,
                        (font_style & WTK_FONT_STYLE_STRIKEOUT) == WTK_FONT_STYLE_STRIKEOUT,
                        lf.lfCharSet,
                        lf.lfOutPrecision,
                        lf.lfClipPrecision,
                        CLEARTYPE_QUALITY /*lf.lfQuality*/,
                        lf.lfPitchAndFamily,
                        &font_family[0]);

    if( !hFont ) return NULL;

    font = wtk_alloc(sizeof(wtk_font));
    memset((void*)font, 0, sizeof(struct wtk_font));
    font->hFont = hFont;

    return font;
}

struct wtk_font* WTK_API wtk_font_default()
{
    static wtk_font def_font = { NULL };
    return &def_font;
}

void WTK_API wtk_font_destroy( struct wtk_font* font )
{
    WTK_ASSERT(font);
    DeleteObject(font->hFont);
    wtk_free(font);
}

void wtk_font_set_user_ptr( struct wtk_font* font, void* user_ptr )
{
    WTK_ASSERT(font);
    font->user_ptr = user_ptr;
}

void* wtk_font_get_user_ptr( struct wtk_font* font )
{
    WTK_ASSERT(font);
    return font->user_ptr;
}
