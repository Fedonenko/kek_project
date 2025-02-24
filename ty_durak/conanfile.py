from conan import ConanFile
from conan.tools.cmake import cmake_layout


class KekProjectRecipe(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	#generators = "CMakeDeps", "CMakeToolchain"
	#generators = "MSBuildDeps", "MSBuildToolchain"
	generators = "MSBuildDeps"
	#generators = "CMakeToolchain"

	def requirements(self):
		#self.requires("libiconv/1.17", override=True)
		#self.requires("harfbuzz/8.3.0")
		#self.requires("crashpad/cci.20220219")
		#self.requires("brotli/1.1.0")
		#self.requires("qt/[>=6.8 <6.8.2]")
		#self.requires("qt/[*]")
		self.requires("qt/6.7.3")

	def build_requirements(self):
		self.tool_requires("cmake/[>=3.25]")

	def configure(self):
		self.options["qt/*"].shared = True
		#self.options["qt/*"].qtmultimedia = True
		self.options["qt/*"].widgets = True
		#self.options["qt/*"].qtsvg = True
		#self.options["qt/*"].with_vulkan = True
		#self.options["qt/*"].qt5compat = True

		#self.options["qt/*"].qtscxml = False

	def layout(self):
		#self.folders.generators = ""
		cmake_layout(self)