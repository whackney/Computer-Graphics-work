# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Lab.Debug:
/Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/Debug/Lab:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/Debug/Lab


PostBuild.Lab.Release:
/Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/Release/Lab:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/Release/Lab


PostBuild.Lab.MinSizeRel:
/Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/MinSizeRel/Lab:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/MinSizeRel/Lab


PostBuild.Lab.RelWithDebInfo:
/Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/RelWithDebInfo/Lab:\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/bhackney/Documents/Computer\ Graphics/Computer-Graphics-work/Lab4_MatrixTransformations/build/RelWithDebInfo/Lab




# For each target create a dummy ruleso the target does not have to exist
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore:
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui:
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL:
/Users/bhackney/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets:
