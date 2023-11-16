workspace "Pixelize"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Inlcude directories 
IncludeDir = {}
IncludeDir["GLFW"] = "Pixelize/vendor/GLFW/include"

include "Pixelize/vendor/GLFW"

project "Pixelize" 
	location "Pixelize"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "plpch.h"
	pchsource "Pixelize/src/plpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"PL_PLATFORM_WINDOWS",
			"PL_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PL_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Pixelize/vendor/spdlog/include",
		"Pixelize/src"
	}

	links { "Pixelize" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"PL_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PL_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PL_DIST"
		optimize "On"