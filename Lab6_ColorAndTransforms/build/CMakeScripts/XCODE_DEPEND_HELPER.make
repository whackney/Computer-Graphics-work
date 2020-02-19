# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.App.Debug:
/Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/Debug/App:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/Debug/App


PostBuild.App.Release:
/Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/Release/App:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/Release/App


PostBuild.App.MinSizeRel:
/Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/MinSizeRel/App:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/MinSizeRel/App


PostBuild.App.RelWithDebInfo:
/Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/RelWithDebInfo/App:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/computer-graphics-partner/ComputerGraphics/Lab6_ColorAndTransforms/build/RelWithDebInfo/App




# For each target create a dummy ruleso the target does not have to exist
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore:
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui:
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL:
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets:
