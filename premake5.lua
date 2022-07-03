workspace "EcoScape"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist" -- Distribution for sending out, no debug or logging
	}

-- Example = Debug-Windows-64
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EcoScape"
	location "EcoScape"
	kind "SharedLib" -- SharedLib = DLL
	language "C++"

	-- Example bin/Debug-Windows-x64/EcoScape
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "precompiledheaders.h"
	pchsource "EcoScape/src/precompiledheaders.cpp"

	files
	{ -- '**' Means search all the folders in that folder too
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/SDL2/include",
		"%{prj.name}/src"
	}

	libdirs
	{
		"EcoScape/vendor/SDL2/lib/x64"
	}

	links
	{
		"SDL2",
		"SDL2main"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On" -- Linking the runtime libraries staticly
		systemversion "latest" -- SDK version

		defines
		{
			"ES_PLATFORM_WINDOWS",
			"ES_BUILD_DLL"
		}

		postbuildcommands
		{ -- relpath = relative path, copies EcoScape.dll to Sandbox
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ES_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ES_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ES_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	-- Example bin/Debug-Windows-x64/EcoScape
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{ -- '**' Means search all the folders in that folder too
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs -- Stuff to include
	{
		-- Example = "%{prj.name}/vendor/sdl/include"
		"EcoScape/src"
	}

	links
	{
		"EcoScape"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On" -- Linking the runtime libraries staticly
		systemversion "latest" -- SDK version

		defines
		{
			"ES_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ES_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ES_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ES_DIST"
		optimize "On"


project "LoggingDev"
	location "LoggingDev"
	kind "ConsoleApp"
	language "C++"

	configmap -- A world made only od debuging
	{
		["Release"] = "Debug",
		["Dist"] = "Debug"
	}

	-- Example bin/Debug-Windows-x64/EcoScape
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{ -- '**' Means search all the folders in that folder too
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On" -- Linking the runtime libraries staticly
		systemversion "latest" -- SDK version

	filter {} -- clears filter
		symbols "On"


project "SDL2Test"
	location "SDL2Test"
	kind "ConsoleApp"
	language "C++"

	configmap
	{
		["Release"] = "Debug",
		["Dist"] = "Debug"
	}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"EcoScape/vendor/SDL2/include"
	}

	libdirs
	{
		"EcoScape/vendor/SDL2/lib/x64"
	}

	links
	{
		"SDL2",
		"SDL2main"
	}

	postbuildcommands
	{ -- relpath = relative path, copies EcoScape.dll to Sandbox
		-- ("{COPY} ../EcoScape/vendor/SDL2/lib/x64/SDL2.dll /bin/" .. outputdir .. "/%{prj.name}")
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On" -- Linking the runtime libraries staticly
		systemversion "latest" -- SDK version

	filter {} -- clears filter
		symbols "On"