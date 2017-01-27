
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


#ifndef _WTK_MM_H_
#define _WTK_MM_H_

#include <wtk/wtk_config.h>
#include <wtk/wtk_compat.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct wtk_allocator {
    void* (WTK_API *alloc_callback)( size_t num_bytes );
    void* (WTK_API *realloc_callback)( void* ptr, size_t num_bytes );
    void (WTK_API *free_callback)( void* ptr );
} wtk_allocator;

extern WTK_EXPORT void WTK_API wtk_set_allocator( const struct wtk_allocator* allocator );
extern WTK_EXPORT const struct wtk_allocator* wtk_get_allocator();

extern WTK_EXPORT void* WTK_API wtk_alloc( size_t num_bytes );
extern WTK_EXPORT void* WTK_API wtk_realloc( void* ptr, size_t num_bytes );
extern WTK_EXPORT void WTK_API wtk_free( void* ptr );

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _WTK_MM_H_
