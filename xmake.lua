add_requires("libsdl2", "glad", {
			configs = {
			    spec = "gl",
			    version = "4.6",
			    profile = "core",
			    extensions = "true",
			    loader = true
			}
})

set_toolchains("gcc-15")
set_languages("cxx23")
add_cxxflags("-pedantic-errors", "-Wall", "-Wextra", "-Wconversion", "-Wsign-conversion", "-Werror", "-g")


target("opengl-triangle")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("libsdl2", "glad")
    add_includedirs("include/")