
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


#ifndef _WTK_IMAGE_LIST_H_
#define _WTK_IMAGE_LIST_H_

#include <wtk/wtk_config.h>
#include <wtk/wtk_compat.h>
#include <wtk/wtk_image.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct wtk_image_list;
typedef struct wtk_image_list wtk_image_list;

extern WTK_EXPORT struct wtk_image_list* WTK_API wtk_image_list_create( int width, int height, int num_imgs );
extern WTK_EXPORT void WTK_API wtk_image_list_destroy( struct wtk_image_list* img_list );

typedef unsigned int wtk_image_list_id;

extern WTK_EXPORT wtk_image_list_id WTK_API wtk_image_list_add_image( struct wtk_image_list* img_list, struct wtk_image* image );
extern WTK_EXPORT wtk_image_list_id WTK_API wtk_image_list_add_icon( struct wtk_image_list* img_list, struct wtk_icon* icon );
extern WTK_EXPORT void wtk_image_list_replace( struct wtk_image_list* img_list, wtk_image_list_id id, struct wtk_image* image );
extern WTK_EXPORT void WTK_API wtk_image_list_remove( struct wtk_image_list* img_list, wtk_image_list_id id );

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _WTK_IMAGE_LIST_H_
