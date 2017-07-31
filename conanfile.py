from conans import ConanFile, CMake


class BitprimdatabaseConan(ConanFile):
    name = "bitprim-database"
    version = "0.1"
    license = "http://www.boost.org/users/license.html"
    url = "https://github.com/bitprim/bitprim-databse"
    description = "Bitcoin High Performance Blockchain Database"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"
    exports_sources = "src/*"
    package_files = "build/lbitprim-database.a"

#    def build(self):
#        cmake = CMake(self)
#        self.run('cmake %s/src %s' % (self.source_folder, cmake.command_line))
#        self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["bitprim-database"]