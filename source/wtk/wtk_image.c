
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

// Author: Michael Williams (mtwilliams)            


#include <wtk/wtk_image.h>

#include "_wtk_windows.h"
#include "_wtk_image.h"

#include <wtk/wtk_mm.h>

#include <string.h>

struct wtk_image* WTK_API wtk_image_create_from_file( const char* file_path, int width, int height )
{
    HANDLE hImage;
    struct wtk_image* image;

    WTK_ASSERT(file_path);

    hImage = LoadImageA(GetModuleHandle(0), file_path, IMAGE_BITMAP,
                        (width == WTK_IMAGE_SIZE_DEFAULT) ? 0 : width,
                        (height == WTK_IMAGE_SIZE_DEFAULT) ? 0 : height,
                        LR_LOADFROMFILE);
    if( !hImage ) return NULL;

    image = wtk_alloc(sizeof(struct wtk_image));
    memset((void*)image, 0, sizeof(struct wtk_image));
    image->hImage = hImage;
    return image;
}

void WTK_API wtk_image_destroy( struct wtk_image* image )
{
    WTK_ASSERT(image);
    DeleteObject(image->hImage);
    wtk_free(image);
}

void WTK_API wtk_image_set_user_ptr( struct wtk_image* image, void* user_ptr )
{
    WTK_ASSERT(image);
    image->user_ptr = user_ptr;
}

void* WTK_API wtk_image_get_user_ptr( struct wtk_image* image )
{
    WTK_ASSERT(image);
    return image->user_ptr;
}

struct wtk_icon* WTK_API wtk_icon_create_from_file( const char* file_path, int width, int height )
{
    HANDLE hIcon;
    struct wtk_icon* icon;

    WTK_ASSERT(file_path);

    hIcon = LoadImageA(GetModuleHandle(0), file_path, IMAGE_ICON,
                        (width == WTK_ICON_SIZE_DEFAULT) ? 0 : width,
                        (height == WTK_ICON_SIZE_DEFAULT) ? 0 : height,
                        LR_LOADFROMFILE);
    if( !hIcon ) return NULL;

    icon = wtk_alloc(sizeof(struct wtk_icon));
    memset((void*)icon, 0, sizeof(struct wtk_icon));
    icon->hIcon = hIcon;
    return icon;
}

void WTK_API wtk_icon_destroy( struct wtk_icon* icon )
{
    WTK_ASSERT(icon);
    DestroyIcon(icon->hIcon);
    wtk_free(icon);
}

void WTK_API wtk_icon_set_user_ptr( struct wtk_icon* icon, void* user_ptr )
{
    WTK_ASSERT(icon);
    icon->user_ptr = user_ptr;
}

void* WTK_API wtk_icon_get_user_ptr( struct wtk_icon* icon )
{
    WTK_ASSERT(icon);
    return icon->user_ptr;
}
