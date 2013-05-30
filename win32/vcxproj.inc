<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" InitialTargets="Info" ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <PropertyGroup Condition="'$(ConfigurationType)'=='DynamicLibrary' OR '$(ConfigurationType)'=='StaticLibrary' ">
    <ConfigurationType>$(UsesConfigurationType)</ConfigurationType>
  </PropertyGroup>
  <PropertyGroup>
	<LibName Condition="'|$(LibName)|'=='||'">$(ProjectName)</LibName>
    <UseDebugLibraries Condition="'$(Configuration)'=='Debug'">true</UseDebugLibraries>
    <UseDebugLibraries Condition="'$(Configuration)'=='Release'">false</UseDebugLibraries>
    <OutNameSuffix Condition="'$(CallingConvention)|$(UsesConfigurationType)'=='Cdecl|DynamicLibrary'"></OutNameSuffix>
    <OutNameSuffix Condition="'$(CallingConvention)|$(UsesConfigurationType)'=='Cdecl|StaticLibrary'">-static</OutNameSuffix>
    <OutNameSuffix Condition="'$(CallingConvention)|$(UsesConfigurationType)'=='stdcall|DynamicLibrary'">-stdcall</OutNameSuffix>
    <OutNameSuffix Condition="'$(CallingConvention)|$(UsesConfigurationType)'=='stdcall|StaticLibrary'">-static-stdcall</OutNameSuffix>
    <OutName>$(LibName)$(OutNameSuffix)</OutName>
    <ProjectRootDir Condition="'$(SolutionDir)' != ''">$(SolutionDir)</ProjectRootDir>
    <ProjectRootDir Condition="'$(SolutionDir)' == ''">.\</ProjectRootDir> 
    <OutDir>$(ProjectRootDir)Output\$(PlatformToolset)\$(Platform)\$(Configuration)\$(UsesConfigurationType)\$(CallingConvention)/</OutDir> 
    <IntDir>$(ProjectRootDir)Intermediate\$(PlatformToolset)\$(Platform)\$(Configuration)\$(UsesConfigurationType)\$(CallingConvention)/</IntDir>
    <TargetName>$(OutName)</TargetName>
  </PropertyGroup>
  <ItemDefinitionGroup>
    <ClCompile>
      <CallingConvention>$(CallingConvention)</CallingConvention>
      <RuntimeLibrary Condition="'$(Configuration)|$(UsesConfigurationType)'=='Debug|DynamicLibrary'">MultiThreadedDebugDLL</RuntimeLibrary>
      <RuntimeLibrary Condition="'$(Configuration)|$(UsesConfigurationType)'=='Debug|StaticLibrary'">MultiThreadedDebug</RuntimeLibrary>
      <RuntimeLibrary Condition="'$(Configuration)|$(UsesConfigurationType)'=='Release|DynamicLibrary'">MultiThreadedDLL</RuntimeLibrary>
      <RuntimeLibrary Condition="'$(Configuration)|$(UsesConfigurationType)'=='Release|StaticLibrary'">MultiThreaded</RuntimeLibrary>
      <WarningLevel>Level3</WarningLevel>
    </ClCompile>
    <Link>
      <GenerateDebugInformation>true</GenerateDebugInformation>
      <OutputFile Condition="'$(ConfigurationType)'=='DynamicLibrary'">$(OutDir)$(OutName).dll</OutputFile>
      <ProgramDatabaseFile>$(OutDir)$(OutName).pdb</ProgramDatabaseFile>
      <ImportLibrary Condition="'$(ConfigurationType)'=='DynamicLibrary'">$(OutDir)$(OutName).lib</ImportLibrary>
      <ProfileGuidedDatabase>$(OutDir)$(OutName).pgd</ProfileGuidedDatabase>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)'=='Debug'">
    <ClCompile>
      <Optimization>Disabled</Optimization>
    </ClCompile>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)'=='Release'">
    <ClCompile>
      <Optimization>MaxSpeed</Optimization>
    </ClCompile>
  </ItemDefinitionGroup>
   <Target Name="Info" BeforeTargets="Build">
    <Message Text="  Configuration     :  '$(Configuration)'" />
    <Message Text="  PlatformToolset   :  '$(PlatformToolset)'" />
    <Message Text="  Platform          :  '$(Platform)'" />
    <Message Text="  ConfigurationType :  '$(ConfigurationType)'" />
    <Message Text="  CallingConvention :  '$(CallingConvention)'" />
	<MakeDir Directories="$(OutDir);$(IntDir);$(TargetDir)"/>
  </Target>
</Project>