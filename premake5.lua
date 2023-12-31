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
IncludeDir["Glad"] = "Pixelize/vendor/glad/include"
IncludeDir["imgui"] = "Pixelize/vendor/imgui/"
IncludeDir["glm"] = "Pixelize/vendor/glm"

group "Dependencies"
	include "Pixelize/vendor/GLFW"
	include "Pixelize/vendor/glad"
	include "Pixelize/vendor/imgui"
group ""

project "Pixelize" 
	location "Pixelize"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"GLAD",
		"opengl32.lib",
		"dwmapi.lib",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"PL_PLATFORM_WINDOWS",
			"PL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "PL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PL_Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PL_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Pixelize/vendor/spdlog/include",
		"Pixelize/src",
		"%{IncludeDir.glm}"
	}

	links { "Pixelize" }

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"PL_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PL_Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PL_DIST"
		runtime "Release"
		optimize "On"