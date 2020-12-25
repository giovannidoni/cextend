import setuptools
from distutils.core import Extension


module = Extension('cex.myext', sources=['cex/myext.c'])

setuptools.setup(
    name="cex",
    version="0.0.1",
    ext_modules = [module],
    long_description_content_type="text/markdown",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.5',
)
