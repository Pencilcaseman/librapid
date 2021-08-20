# coding: utf8

import os
import platform
import sys
from pathlib import Path

ROOT_DIR = os.path.dirname(os.path.abspath(__file__))

# If using windows, tell the os where the DLL for blas is
# If blas was not installed, this doesn't really do anything
if platform.system() == "Windows":
	import win32api

	win32api.SetDllDirectory(ROOT_DIR)
	sys.path.append(ROOT_DIR)

try:
	try:
		print("Attempting to load '._librapid' from {}".format(os.listdir(ROOT_DIR)))
		from ._librapid import *
	except ModuleNotFoundError:
		print("Failed to load '._librapid'. Attempting to load '_librapid' globally")
		from _librapid import *
except ImportError:
	print("There was an error trying to load the librapid C++ module '_librapid'")
	
	if platform.system() == "Windows":
		print("This could be caused by a missing BLAS DLL file in the '{}' directory".format(ROOT_DIR))
		print("\n".join(os.listdir(ROOT_DIR)))

	raise ImportError("Could not import '_librapid'")
