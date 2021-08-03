from conans import ConanFile, CMake


class LakeConan(ConanFile):
    name = 'lake'
    version = '0.1'
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'cmake_find_package', 'cmake'
    requires = 'fmt/8.0.1', 'entt/3.8.0', 'glfw/3.3.4', 'glm/0.9.9.8', 'boost/1.76.0', 'glad/0.1.34'

    def source(self):
        self.run('git clone https://github.com/maciejjablonsky/lake.git')

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
