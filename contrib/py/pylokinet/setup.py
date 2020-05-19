from setuptools import setup, find_packages



setup(
  name="pycoiniclesnet",
  version="0.0.1",
  license="ZLIB",
  author="jeff",
  author_email="jeff@i2p.rocks",
  description="coiniclesnet python bindings",
  url="https://github.com/coinicles-project/coinicles-network",
  install_requires=["pysodium", "requests", "python-dateutil"],
  packages=find_packages())