#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/estruturasdedadoscpp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/estruturasdedadoscpp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/estruturasdedadoscpp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Lista01Questao01.h.gch: Lista01Questao01.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista01Questao01.h

${OBJECTDIR}/Lista01Questao02.h.gch: Lista01Questao02.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista01Questao02.h

${OBJECTDIR}/Lista01Questao03.h.gch: Lista01Questao03.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista01Questao03.h

${OBJECTDIR}/Lista01Questao04.h.gch: Lista01Questao04.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista01Questao04.h

${OBJECTDIR}/Lista01Questao05.h.gch: Lista01Questao05.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista01Questao05.h

${OBJECTDIR}/Lista02Questao01.h.gch: Lista02Questao01.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista02Questao01.h

${OBJECTDIR}/Lista02Questao02.h.gch: Lista02Questao02.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista02Questao02.h

${OBJECTDIR}/Lista02Questao03.h.gch: Lista02Questao03.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista02Questao03.h

${OBJECTDIR}/Lista02Questao04.h.gch: Lista02Questao04.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista02Questao04.h

${OBJECTDIR}/Lista02Questao06.h.gch: Lista02Questao06.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista02Questao06.h

${OBJECTDIR}/Lista03Questao01.h.gch: Lista03Questao01.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista03Questao01.h

${OBJECTDIR}/Lista04Questao01.h.gch: Lista04Questao01.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" Lista04Questao01.h

${OBJECTDIR}/bibliotecas.h.gch: bibliotecas.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" bibliotecas.h

${OBJECTDIR}/classeExpressoes.h.gch: classeExpressoes.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" classeExpressoes.h

${OBJECTDIR}/classeLista.h.gch: classeLista.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" classeLista.h

${OBJECTDIR}/classeListaEncadeada.h.gch: classeListaEncadeada.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" classeListaEncadeada.h

${OBJECTDIR}/classeMatriz.h.gch: classeMatriz.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" classeMatriz.h

${OBJECTDIR}/classePilha.h.gch: classePilha.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" classePilha.h

${OBJECTDIR}/funcoesAuxiliares.h.gch: funcoesAuxiliares.h
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o "$@" funcoesAuxiliares.h

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
