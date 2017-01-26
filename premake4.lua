
-- This is free and unencumbered software released into the public domain.  

-- Anyone is free to copy, modify, publish, use, compile, sell, or           
-- distribute this software, either in source code form or as a compiled    
-- binary, for any purpose, commercial or non-commercial, and by any        
-- means.                                                                   

-- In jurisdictions that recognize copyright laws, the author or authors    
-- of this software dedicate any and all copyright interest in the           
-- software to the public domain. We make this dedication for the benefit    
-- of the public at large and to the detriment of our heirs and              
-- successors. We intend this dedication to be an overt act of               
-- relinquishment in perpetuity of all present and future rights to this     
-- software under copyright law.                                             

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          
-- EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF        
-- MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    
-- IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR         
-- OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
-- ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR     
-- OTHER DEALINGS IN THE SOFTWARE.                                           

-- For more information, please refer to <http://unlicense.org/>             


if _ACTION and _ACTION ~= "help" then

solution "wtk"
    location("build/" .. _ACTION)
    configurations({ "debug", "release" })

    project("sample")
        kind("WindowedApp")
        language("C")
        objdir("build/" .. _ACTION .. "/sample/obj" )
        targetdir("bin/" .. _ACTION .. "/")
        targetname("sample")
        debugdir("sample")

        configuration("debug") targetsuffix("-dbg") flags({ "Symbols" }) links("libwtk")
        configuration("release") flags({ "Optimize", "EnableSSE", "EnableSSE2" }) links("libwtk")

        configuration({})
            libdirs({ "lib/" .. _ACTION })
            defines({ "WTK_DLL" })
            includedirs({ "include" })
            files { "sample/**.c" }

    project("libwtk")
        kind("SharedLib")
        language("C")
        objdir("build/" .. _ACTION .. "/libwtk/obj" )
        targetdir("lib/" .. _ACTION .. "/")
        targetname("wtk")

        configuration("debug") targetsuffix("-dbg") flags({ "Symbols" })
        configuration("release") flags({ "Optimize", "EnableSSE", "EnableSSE2" })

        configuration({})
            defines({ "WTK_DLL", "WTK_BUILD" })
            includedirs { "include" }
            files { "include/**.h", "include/**.inl", "source/**.c" }

        configuration("windows")
            links({ "comctl32" })
            defines({ "ISOLATION_AWARE_ENABLED=1" })
            postbuildcommands({ "move \"..\\..\\lib\\" .. _ACTION .. "\\*.dll\" \"..\\..\\bin\\" .. _ACTION .. "\\\"" })
end
