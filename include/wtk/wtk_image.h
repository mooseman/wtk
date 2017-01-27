
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


#ifndef _WTK_IMAGE_H_
#define _WTK_IMAGE_H_

#include <wtk/wtk_config.h>
#include <wtk/wtk_compat.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct wtk_image;
typedef struct wtk_image wtk_image;

struct wtk_icon;
typedef struct wtk_icon wtk_icon;

#define WTK_IMAGE_SIZE_DEFAULT -1
#define WTK_ICON_SIZE_DEFAULT -1

extern WTK_EXPORT struct wtk_image* WTK_API wtk_image_create_from_file( const char* file_path, int width, int height );
extern WTK_EXPORT void WTK_API wtk_image_destroy( struct wtk_image* image );

extern WTK_EXPORT void WTK_API wtk_image_set_user_ptr( struct wtk_image* image, void* user_ptr );
extern WTK_EXPORT void* WTK_API wtk_image_get_user_ptr( struct wtk_image* image );

extern WTK_EXPORT struct wtk_icon* WTK_API wtk_icon_create_from_file( const char* file_path, int width, int height );
extern WTK_EXPORT void WTK_API wtk_icon_destroy( struct wtk_icon* icon );

extern WTK_EXPORT void WTK_API wtk_icon_set_user_ptr( struct wtk_icon* icon, void* user_ptr );
extern WTK_EXPORT void* WTK_API wtk_icon_get_user_ptr( struct wtk_icon* icon );

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _WTK_IMAGE_H_
