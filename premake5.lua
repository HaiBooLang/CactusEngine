workspace "CactusEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CactusEngine"
	location "CactusEngine"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CC_PLATFORM_WINDOWS",
			"CC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CC_DIST"
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
		"CactusEngine/vendor/spdlog/include",
		"CactusEngine/src"
	}

	links
	{
		"CactusEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CC_DIST"
		optimize "On"