
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


#include <wtk/wtk_mm.h>

static const struct wtk_allocator* _allocator = NULL;

void WTK_API wtk_set_allocator( const struct wtk_allocator* allocator )
{
    _allocator = allocator;
}

const struct wtk_allocator* wtk_get_allocator()
{
    return _allocator;
}

void* WTK_API wtk_alloc( size_t num_bytes )
{
    WTK_ASSERT(_allocator);
    return _allocator->alloc_callback(num_bytes);
}

void* WTK_API wtk_realloc( void* ptr, size_t num_bytes )
{
    WTK_ASSERT(_allocator);
    return _allocator->realloc_callback(ptr, num_bytes);
}

void WTK_API wtk_free( void* ptr )
{
    WTK_ASSERT(_allocator);
    WTK_ASSERT(ptr);
    _allocator->free_callback(ptr);
}
