#include "FlashExporter.h"
#include "Files.h"
#include "ImageTool.h"
#include "SoundTool.h"
#include <sstream>

using namespace hake;
using namespace kake;

FlashExporter::FlashExporter(kake::Path directory) : directory(directory) {
	
}

void FlashExporter::exportSolution(Platform platform, Path haxeDirectory) {
	writeFile(directory.resolve("Project.hxproj"));
	p("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	p("<project version=\"2\">");
		p("<!-- Output SWF options -->", 1);
		p("<output>", 1);
		p("<movie outputType=\"Application\" />", 2);
		p("<movie input=\"\" />", 2);
		p("<movie path=\"bin\\sml.swf\" />", 2);
		p("<movie fps=\"60\" />", 2);
		std::stringstream w;
		w << "<movie width=\"" << width << "\" />";
		p(w.str(), 2);
		std::stringstream h;
		h << "<movie height=\"" << height << "\" />";
		p(h.str(), 2);
		p("<movie version=\"11\" />", 2);
		p("<movie minorVersion=\"2\" />", 2);
		p("<movie platform=\"Flash Player\" />", 2);
		p("<movie background=\"#FFFFFF\" />", 2);
		if (Files::isDirectory(haxeDirectory)) p("<movie preferredSDK=\"" + haxeDirectory.toString() + "\" />", 2);
		p("</output>", 1);
		p("<!-- Other classes to be compiled into your SWF -->", 1);
		p("<classpaths>", 1);
		p("<class path=\"..\\Sources\" />", 2);
		p("<class path=\"..\\Kha\\Sources\" />", 2);
		p("<class path=\"..\\Kha\\Backends\\Flash\" />", 2);
		p("</classpaths>", 1);
		p("<!-- Build options -->", 1);
		p("<build>", 1);
		p("<option directives=\"\" />", 2);
		p("<option flashStrict=\"False\" />", 2);
		p("<option mainClass=\"Main\" />", 2);
		p("<option enabledebug=\"True\" />", 2);
		p("<option additional=\"\" />", 2);
		p("</build>", 1);
		p("<!-- haxelib libraries -->", 1);
		p("<haxelib>", 1);
		p("<!-- example: <library name=\"...\" /> -->", 2);
		p("</haxelib>", 1);
		p("<!-- Class files to compile (other referenced classes will automatically be included) -->", 1);
		p("<compileTargets>", 1);
		p("<compile path=\"..\\Sources\\Main.hx\" />", 2);
		p("</compileTargets>", 1);
		p("<!-- Assets to embed into the output SWF -->", 1);
		p("<library>", 1);
		p("<!-- example: <asset path=\"...\" id=\"...\" update=\"...\" glyphs=\"...\" mode=\"...\" place=\"...\" sharepoint=\"...\" /> -->", 2);
		p("</library>", 1);
		p("<!-- Paths to exclude from the Project Explorer tree -->", 1);
		p("<hiddenPaths>", 1);
		p("<!-- example: <hidden path=\"...\" /> -->", 2);
		p("</hiddenPaths>", 1);
		p("<!-- Executed before build -->", 1);
		p("<preBuildCommand />", 1);
		p("<!-- Executed after build -->", 1);
		p("<postBuildCommand alwaysRun=\"False\" />", 1);
		p("<!-- Other project options -->", 1);
		p("<options>", 1);
		p("<option showHiddenPaths=\"False\" />", 2);
		p("<option testMovie=\"Default\" />", 2);
		p("</options>", 1);
		p("<!-- Plugin storage -->", 1);
		p("<storage />", 1);
	p("</project>");
	closeFile();
}

void FlashExporter::copyMusic(Platform platform, Path from, Path to, std::string oggEncoder, std::string aacEncoder, std::string mp3Encoder) {
	convertSound(from, directory.resolve("flash").resolve(to.toString() + ".mp3"), mp3Encoder);
}

void FlashExporter::copySound(Platform platform, Path from, Path to, std::string oggEncoder, std::string aacEncoder, std::string mp3Encoder) {
	convertSound(from, directory.resolve("flash").resolve(to.toString() + ".mp3"), mp3Encoder);
}

void FlashExporter::copyImage(Platform platform, Path from, Path to, Json::Value& asset) {
	exportImage(from, directory.resolve("flash").resolve(to), asset);
}

void FlashExporter::copyBlob(Platform platform, Path from, Path to) {
	copyFile(from, directory.resolve("flash").resolve(to));
}
