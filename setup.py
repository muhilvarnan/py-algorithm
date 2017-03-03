from distutils.core import setup, Extension
import numpy.distutils.misc_util
from setuptools import setup, find_packages

setup(
	name='py_ds',
    version='0.0.1',
    description='Python datastructure module',
    url='https://github.com/muhilvarnan/python_sms_gateway',
    author='muhilvarnan',
    author_email='muhilvarnan.v@gmail.com',
    license='MIT',
    packages=find_packages(),
    zip_safe=False,
    ext_modules=[Extension("_segment_tree", ["c/py/_segment_tree.c", "c/segment_tree.c"])],
    include_dirs=numpy.distutils.misc_util.get_numpy_include_dirs()
)