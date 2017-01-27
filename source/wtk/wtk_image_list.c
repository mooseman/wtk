
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


#include <wtk/wtk_image_list.h>

#include "_wtk_windows.h"
#include "_wtk_image.h"

#include <wtk/wtk_mm.h>

#include <string.h>

struct wtk_image_list* WTK_API wtk_image_list_create( int width, int height, int num_imgs )
{
    HIMAGELIST hImageList;
    struct wtk_image_list* img_list;

    hImageList = ImageList_Create(width, height, ILC_COLOR32, num_imgs, num_imgs);
    if( !hImageList ) return NULL;

    img_list = (struct wtk_image_list*)wtk_alloc(sizeof(struct wtk_image_list));
    img_list->hImageList = hImageList;
    return img_list;
}

void WTK_API wtk_image_list_destroy( struct wtk_image_list* img_list )
{
    WTK_ASSERT(img_list);

    ImageList_Destroy(img_list->hImageList);
    wtk_free(img_list);
}

wtk_image_list_id WTK_API wtk_image_list_add_image( struct wtk_image_list* img_list, struct wtk_image* image )
{
    WTK_ASSERT(img_list);
    WTK_ASSERT(image);

    return (wtk_image_list_id)(ImageList_Add(img_list->hImageList, (HBITMAP)image->hImage, NULL) + 1);
}


wtk_image_list_id WTK_API wtk_image_list_add_icon( struct wtk_image_list* img_list, struct wtk_icon* icon )
{
    WTK_ASSERT(img_list);
    WTK_ASSERT(icon);

    return (wtk_image_list_id)(ImageList_AddIcon(img_list->hImageList, icon->hIcon) + 1);
}

void wtk_image_list_replace( struct wtk_image_list* img_list, wtk_image_list_id id, struct wtk_image* image )
{
    WTK_ASSERT(img_list);
    WTK_ASSERT(id > 0);
    WTK_ASSERT(image);

    ImageList_Replace(img_list->hImageList, id - 1, image->hImage, NULL);
}

void WTK_API wtk_image_list_remove( struct wtk_image_list* img_list, wtk_image_list_id id )
{
    WTK_ASSERT(img_list);
    WTK_ASSERT(id > 0);

    ImageList_Remove(img_list->hImageList, id - 1);
}
