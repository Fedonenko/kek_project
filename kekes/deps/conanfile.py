from conan import ConanFile
from conan.tools.cmake import cmake_layout


class KekProjectRecipe(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	#generators = "CMakeDeps", "CMakeToolchain"
	#generators = "MSBuildDeps", "MSBuildToolchain"
	generators = "MSBuildDeps"
	#generators = "CMakeToolchain"

	def requirements(self):
		self.requires("harfbuzz/8.3.0")
		#self.requires("crashpad/cci.20220219")
		self.requires("qt/6.8.3")

	def build_requirements(self):
		self.tool_requires("cmake/[>=3.25]")
		self.tool_requires("meson/1.3.0")

	def configure(self):
		self.options["qt/*"].shared = True
		#self.options["qt/*"].with_sqlite3 = True
		self.options["qt/*"].with_sqlite3 = False

		self.options["qt/*"].qtmultimedia = True
		self.options["qt/*"].widgets = True
		self.options["qt/*"].gui = True
		self.options["qt/*"].qttools = True
		self.options["qt/*"].qtdeclarative = True
		self.options["qt/*"].qtwebchannel = True

		self.options["qt/*"].qtshadertools = True

		self.options["qt/*"].qtwebsockets = True
		self.options["qt/*"].qtwebview = True

		self.options["qt/*"].qtsvg = True
		#self.options["qt/*"].with_vulkan = True
		#self.options["qt/*"].qt5compat = True

	def layout(self):
		#self.folders.generators = ""
		cmake_layout(self)