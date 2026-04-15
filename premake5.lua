workspace "Kick"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kick"
	location "Kick"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"KC_PLATFORM_WINDOWS",
			"KC_BUILD_DLL"
		}

		postbuildcommands
		{

			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kick/vendor/spdlog/include",
		"Kick/src"
	}

	links
	{
		"Kick"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"KC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KC_DIST"
		optimize "On"