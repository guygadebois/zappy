#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2014/06/02 21:00:14 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources libft
.SUFFIXES:

export CC = gcc
CCPP = g++ -std=c++98 -pedantic
NAME = zappy
SERVEUR_NAME = serveur
CLIENT_NAME = client
VISU_NAME = visu
FLAGS = -Wall -Wextra -Werror -ggdb -g
INCL_FLAGS = -Iinclude -Iinclude/models -Iinclude/visu_models -Ilibft/include
IRRLICHT_INCL_FLAGS = -I irrlicht/include

ifeq ($(shell uname), Linux)
IRRLICHT_LDFLAGS= -L ../irrlicht-trunk/lib/Linux -l Irrlicht -l GL -lXext \
-lX11 -lGLU -lXxf86vm
else
IRRLICHT_LDFLAGS= -L irrlicht/lib -l Irrlicht -framework OpenGL \
-framework Cocoa -framework Carbon -framework IOKit
endif
CFLAGS = $(INCL_FLAGS) $(FLAGS) $(IRRLICHT_INCL_FLAGS)
LDFLAGS = -Llibft -lft

SERVEUR_OFILES = $(notdir $(SERVEUR_CFILES:.c=.o))
CLIENT_OFILES = $(notdir $(CLIENT_CPPFILES:.cpp=.o))
VISU_OFILES = $(notdir $(VISU_CPPFILES:.cpp=.o))
COMMON_CPP_OFILES = $(notdir $(COMMON_CPPFILES:.cpp=.o))

OFILES = $(notdir $(CFILES:.c=.o)) $(notdir $(CPPFILES:.cpp=.o))
# START INSERT .source

SERVEUR_CFILES= \
		serveur_src/main.c \

CLIENT_CPPFILES= \
		client_src/main.cpp \

VISU_CPPFILES= \
		visu_src/main.cpp \
		visu_src/models/Engine.cpp \

COMMON_CPPFILES= \

CFILES= $(SERVEUR_CFILES)
CPPFILES= $(CLIENT_CPPFILES) $(VISU_CPPFILES) $(COMMON_CPPFILES)


# END INSERT
SRCDIR = src/

SERVEUR_SRCDIR = src/serveur_src/
CLIENT_SRCDIR = src/client_src/
VISU_SRCDIR = src/visu_src/
COMMON_CPP_SRCDIR = src/common_cpp_src/

OBJDIR = obj/

SERVEUR_OBJ = $(addprefix $(OBJDIR)sv_,$(SERVEUR_OFILES))
CLIENT_OBJ = $(addprefix $(OBJDIR)cl_,$(CLIENT_OFILES))
VISU_OBJ = $(addprefix $(OBJDIR)visu_,$(VISU_OFILES))
COMMON_CPP_OBJ = $(addprefix($(OBJDIR)cm_,$(COMMON_OFILES))

OBJ = $(SERVEUR_OBJ) $(CLIENT_OBJ) $(VISU_OBJ) $(COMMON_CPP_OBJ)

CYAN = "\033[36m"
BLUE = "\033[34;1;3m"
GREEN = "\033[32m"
IGREEN = "\033[30;42m"
RED = "\033[31m"
IRED = "\033[0;37;41m"
BRED = "\033[31;1m"
END = "\033[0m"

all: $(NAME)
a: all clean

$(NAME): $(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME)

$(SERVEUR_NAME): libft/libft.a $(SERVEUR_OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CC) -o $@ $(SERVEUR_OBJ) $(CFLAGS) $(LDFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJ) $(COMMON_CPP_OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CCPP) -o $@ $(CLIENT_OBJ) $(COMMON_CPP_OBJ) $(CFLAGS)

$(VISU_NAME): $(VISU_OBJ) $(COMMON_CPP_OBJ)
	@rm -f visu
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
ifeq ($(shell uname), Linux)
	@$(CCPP) -o $@ $(VISU_OBJ) $(COMMON_CPP_OBJ) $(INCL_FLAGS) \
$(IRRLICHT_INCL_FLAGS) $(IRRLICHT_LDFLAGS)
else
	@$(CCPP) -o $@ $(VISU_OBJ) $(COMMON_CPP_OBJ) $(INCL_FLAGS) \
$(IRRLICHT_INCL_FLAGS) $(IRRLICHT_LDFLAGS) 2>/dev/null \
|| echo '\033[31mERROR: visu linking failed...\033[0m'
	@lipo -create visu -output visu.app/Contents/MacOS/visu \
&& rm visu && ln -s visu.app/Contents/MacOS visu
endif

libft/libft.a:
	@make -C libft

fclean: clean
	@make -C libft $@
	@/bin/rm -f $(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME) visu.app/Contents/MacOS/visu
	@echo $(BRED)"    === Removing "$(SERVEUR_NAME) $(CLIENT_NAME) $(VISU_NAME)$(END)

sclean:
	@/bin/rm -f $(OBJ)
	@echo $(RED)"    --> Removing .o files"$(END)

clean: sclean
	@make -C libft $@

r: sclean all
re:	fclean all
# IGNORE NEXT LINES


obj/sv_main.o: src/serveur_src/main.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo $(CYAN)"    Creating obj/sv_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)sv_main.o \
-c $(SRCDIR)serveur_src/main.c $(CFLAGS)

obj/cl_main.o: src/client_src/main.cpp
	@echo $(CYAN)"    Creating obj/cl_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)cl_main.o \
-c $(SRCDIR)client_src/main.cpp $(CFLAGS)

obj/visu_main.o: src/visu_src/main.cpp irrlicht/include/irrlicht.h \
 irrlicht/include/IrrCompileConfig.h irrlicht/include/aabbox3d.h \
 irrlicht/include/irrMath.h irrlicht/include/irrTypes.h \
 irrlicht/include/plane3d.h irrlicht/include/vector3d.h \
 irrlicht/include/line3d.h irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h \
 include/visu_models/Engine.h
	@echo $(CYAN)"    Creating obj/visu_main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_main.o \
-c $(SRCDIR)visu_src/main.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

obj/visu_Engine.o: src/visu_src/models/Engine.cpp include/visu_models/Engine.h \
 irrlicht/include/irrlicht.h irrlicht/include/IrrCompileConfig.h \
 irrlicht/include/aabbox3d.h irrlicht/include/irrMath.h \
 irrlicht/include/irrTypes.h irrlicht/include/plane3d.h \
 irrlicht/include/vector3d.h irrlicht/include/line3d.h \
 irrlicht/include/CDynamicMeshBuffer.h \
 irrlicht/include/IDynamicMeshBuffer.h irrlicht/include/IMeshBuffer.h \
 irrlicht/include/IReferenceCounted.h irrlicht/include/SMaterial.h \
 irrlicht/include/SColor.h irrlicht/include/matrix4.h \
 irrlicht/include/vector2d.h irrlicht/include/dimension2d.h \
 irrlicht/include/rect.h irrlicht/include/position2d.h \
 irrlicht/include/irrString.h irrlicht/include/irrAllocator.h \
 irrlicht/include/irrArray.h irrlicht/include/heapsort.h \
 irrlicht/include/EMaterialTypes.h irrlicht/include/EMaterialFlags.h \
 irrlicht/include/SMaterialLayer.h irrlicht/include/S3DVertex.h \
 irrlicht/include/SVertexIndex.h irrlicht/include/EHardwareBufferFlags.h \
 irrlicht/include/EPrimitiveTypes.h irrlicht/include/IVertexBuffer.h \
 irrlicht/include/IIndexBuffer.h irrlicht/include/CVertexBuffer.h \
 irrlicht/include/CIndexBuffer.h irrlicht/include/CMeshBuffer.h \
 irrlicht/include/coreutil.h irrlicht/include/path.h \
 irrlicht/include/IProfiler.h irrlicht/include/ITimer.h \
 irrlicht/include/ECullingTypes.h irrlicht/include/EDebugSceneTypes.h \
 irrlicht/include/EDriverFeatures.h irrlicht/include/EDriverTypes.h \
 irrlicht/include/EGUIAlignment.h irrlicht/include/EGUIElementTypes.h \
 irrlicht/include/EMeshWriterEnums.h irrlicht/include/EMessageBoxFlags.h \
 irrlicht/include/ESceneNodeAnimatorTypes.h \
 irrlicht/include/ESceneNodeTypes.h irrlicht/include/ETerrainElements.h \
 irrlicht/include/fast_atof.h irrlicht/include/IAnimatedMesh.h \
 irrlicht/include/IMesh.h irrlicht/include/IAnimatedMeshMD2.h \
 irrlicht/include/IAnimatedMeshMD3.h irrlicht/include/IQ3Shader.h \
 irrlicht/include/IFileSystem.h irrlicht/include/IXMLReader.h \
 irrlicht/include/irrXML.h irrlicht/include/IFileArchive.h \
 irrlicht/include/IReadFile.h irrlicht/include/IFileList.h \
 irrlicht/include/IVideoDriver.h irrlicht/include/ITexture.h \
 irrlicht/include/IImage.h irrlicht/include/triangle3d.h \
 irrlicht/include/SExposedVideoData.h irrlicht/include/quaternion.h \
 irrlicht/include/irrpack.h irrlicht/include/irrunpack.h \
 irrlicht/include/IAnimatedMeshSceneNode.h irrlicht/include/ISceneNode.h \
 irrlicht/include/IAttributeExchangingObject.h \
 irrlicht/include/ISceneNodeAnimator.h irrlicht/include/IAttributes.h \
 irrlicht/include/line2d.h irrlicht/include/EAttributes.h \
 irrlicht/include/IEventReceiver.h irrlicht/include/ILogger.h \
 irrlicht/include/Keycodes.h irrlicht/include/ITriangleSelector.h \
 irrlicht/include/irrList.h irrlicht/include/IBoneSceneNode.h \
 irrlicht/include/IBillboardSceneNode.h \
 irrlicht/include/IBillboardTextSceneNode.h \
 irrlicht/include/ICameraSceneNode.h irrlicht/include/ICursorControl.h \
 irrlicht/include/IDummyTransformationSceneNode.h \
 irrlicht/include/IGeometryCreator.h \
 irrlicht/include/IGPUProgrammingServices.h \
 irrlicht/include/EShaderTypes.h irrlicht/include/IGUIButton.h \
 irrlicht/include/IGUIElement.h irrlicht/include/IGUICheckBox.h \
 irrlicht/include/IGUIColorSelectDialog.h irrlicht/include/IGUIComboBox.h \
 irrlicht/include/IGUIContextMenu.h irrlicht/include/IGUIEditBox.h \
 irrlicht/include/IGUIElementFactory.h irrlicht/include/IGUIEnvironment.h \
 irrlicht/include/IGUISkin.h irrlicht/include/EFocusFlags.h \
 irrlicht/include/IGUIFileOpenDialog.h irrlicht/include/IGUIFont.h \
 irrlicht/include/IGUIFontBitmap.h irrlicht/include/IGUIImage.h \
 irrlicht/include/IGUIInOutFader.h irrlicht/include/IGUIListBox.h \
 irrlicht/include/IGUIMeshViewer.h irrlicht/include/IGUIScrollBar.h \
 irrlicht/include/IGUISpinBox.h irrlicht/include/IGUISpriteBank.h \
 irrlicht/include/IGUIStaticText.h irrlicht/include/IGUITabControl.h \
 irrlicht/include/IGUITable.h irrlicht/include/IGUIToolbar.h \
 irrlicht/include/IGUIWindow.h irrlicht/include/IGUITreeView.h \
 irrlicht/include/IGUIImageList.h irrlicht/include/IGUIProfiler.h \
 irrlicht/include/IImageLoader.h irrlicht/include/IImageWriter.h \
 irrlicht/include/ILightSceneNode.h irrlicht/include/SLight.h \
 irrlicht/include/IMaterialRenderer.h \
 irrlicht/include/IMaterialRendererServices.h \
 irrlicht/include/IMeshCache.h irrlicht/include/IMeshLoader.h \
 irrlicht/include/IMeshTextureLoader.h \
 irrlicht/include/IMeshManipulator.h \
 irrlicht/include/SVertexManipulator.h irrlicht/include/IMeshSceneNode.h \
 irrlicht/include/IMeshWriter.h irrlicht/include/IColladaMeshWriter.h \
 irrlicht/include/IMetaTriangleSelector.h irrlicht/include/IOSOperator.h \
 irrlicht/include/IParticleSystemSceneNode.h \
 irrlicht/include/IParticleAnimatedMeshSceneNodeEmitter.h \
 irrlicht/include/IParticleEmitter.h irrlicht/include/SParticle.h \
 irrlicht/include/IParticleBoxEmitter.h \
 irrlicht/include/IParticleCylinderEmitter.h \
 irrlicht/include/IParticleMeshEmitter.h \
 irrlicht/include/IParticleRingEmitter.h \
 irrlicht/include/IParticleSphereEmitter.h \
 irrlicht/include/IParticleAttractionAffector.h \
 irrlicht/include/IParticleAffector.h \
 irrlicht/include/IParticleFadeOutAffector.h \
 irrlicht/include/IParticleGravityAffector.h \
 irrlicht/include/IParticleRotationAffector.h \
 irrlicht/include/IQ3LevelMesh.h irrlicht/include/IRandomizer.h \
 irrlicht/include/IrrlichtDevice.h irrlicht/include/EDeviceTypes.h \
 irrlicht/include/IVideoModeList.h irrlicht/include/irrMap.h \
 irrlicht/include/ISceneCollisionManager.h \
 irrlicht/include/ISceneLoader.h irrlicht/include/ISceneManager.h \
 irrlicht/include/SceneParameters.h irrlicht/include/ISkinnedMesh.h \
 irrlicht/include/SSkinMeshBuffer.h \
 irrlicht/include/ISceneNodeAnimatorCameraFPS.h \
 irrlicht/include/ISceneNodeAnimatorCameraMaya.h \
 irrlicht/include/ISceneNodeAnimatorCollisionResponse.h \
 irrlicht/include/ISceneNodeAnimatorFactory.h \
 irrlicht/include/ISceneNodeFactory.h \
 irrlicht/include/ISceneUserDataSerializer.h \
 irrlicht/include/IShaderConstantSetCallBack.h \
 irrlicht/include/IShadowVolumeSceneNode.h \
 irrlicht/include/ITerrainSceneNode.h irrlicht/include/ITextSceneNode.h \
 irrlicht/include/IVolumeLightSceneNode.h irrlicht/include/IWriteFile.h \
 irrlicht/include/IXMLWriter.h irrlicht/include/ILightManager.h \
 irrlicht/include/SAnimatedMesh.h \
 irrlicht/include/SIrrCreationParameters.h irrlicht/include/SKeyMap.h \
 irrlicht/include/SMesh.h irrlicht/include/SMeshBuffer.h \
 irrlicht/include/SMeshBufferLightMap.h \
 irrlicht/include/SMeshBufferTangents.h \
 irrlicht/include/SSharedMeshBuffer.h irrlicht/include/SViewFrustum.h
	@echo $(CYAN)"    Creating obj/visu_Engine.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CCPP) -o $(OBJDIR)visu_Engine.o \
-c $(SRCDIR)visu_src/models/Engine.cpp $(INCL_FLAGS) $(IRRLICHT_INCL_FLAGS)

