from distutils.core import setup, Extension
import numpy.distutils.misc_util

setup(
    ext_modules=[Extension("_segment_tree", ["c/py/_segment_tree.c", "c/segment_tree.c"])],
    include_dirs=numpy.distutils.misc_util.get_numpy_include_dirs(),
)