#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.



###
## global definitions
###
set_property(GLOBAL PROPERTY USE_FOLDERS ON)



###
## group javascript objects (only for reference)
###
set(SOURCES_JS
    src/Layer0_Javascript/AutoCorrect.js
    src/Layer0_Javascript/ChangeTracking.js
    src/Layer0_Javascript/Clipboard.js
    src/Layer0_Javascript/Cursor.js
    src/Layer0_Javascript/DOM.js
    src/Layer0_Javascript/Editor.js
    src/Layer0_Javascript/elementtypes
    src/Layer0_Javascript/ElementTypes.js
    src/Layer0_Javascript/Equations.js
    src/Layer0_Javascript/Figures.js
    src/Layer0_Javascript/first.js
    src/Layer0_Javascript/Formatting.js
    src/Layer0_Javascript/Hierarchy.js
    src/Layer0_Javascript/Input.js
    src/Layer0_Javascript/Lists.js
    src/Layer0_Javascript/Main.js
    src/Layer0_Javascript/Metadata.js
    src/Layer0_Javascript/NodeSet.js
    src/Layer0_Javascript/Outline.js
    src/Layer0_Javascript/Position.js
    src/Layer0_Javascript/PostponedActions.js
    src/Layer0_Javascript/Preview.js
    src/Layer0_Javascript/Range.js
    src/Layer0_Javascript/Scan.js
    src/Layer0_Javascript/Selection.js
    src/Layer0_Javascript/StringBuilder.js
    src/Layer0_Javascript/Styles.js
    src/Layer0_Javascript/Tables.js
    src/Layer0_Javascript/Text.js
    src/Layer0_Javascript/traversal.js
    src/Layer0_Javascript/types.js
    src/Layer0_Javascript/UndoManager.js
    src/Layer0_Javascript/util.js
    src/Layer0_Javascript/Viewport.js
    src/Layer0_Javascript/empty.html
    src/Layer0_Javascript/check-dom-methods.sh
   )

set(SOURCES_JS_3rdparty
    src/Layer0_Javascript/3rdparty/showdown/showdown.js
   )

set(SOURCES_JS_dtdsource
    src/Layer0_Javascript/dtdsource/dtd.js
    src/Layer0_Javascript/dtdsource/gen_dtd_data.html
    src/Layer0_Javascript/dtdsource/html4.dtd
    src/Layer0_Javascript/dtdsource/html4.xml
   )

set(SOURCES_JS_elementtypes
    src/Layer0_Javascript/elementtypes/genelementtypes.pl
    src/Layer0_Javascript/elementtypes/elements.txt
   )

###
## group source objects
###
set(SOURCES
    src/main.c)



###
# Common include for all platform files
###
include_directories()
include_directories(SYSTEM ${INCLUDE_DIRS})
include_directories(.)
include_directories(SYSTEM ../../../DocFormats/api/headers)
include_directories(../../../DocFormats/headers)
include_directories(../../../DocFormats/core/src/lib)
include_directories(../../../DocFormats/unittest)
link_directories(${LIB_DIRS})



###
# executable (release artifact)
###
add_executable(corinthia ${SOURCES})
target_link_libraries(corinthia DocFormats ${LIBS})
source_group(src FILES ${SOURCES})

source_group(javascript FILES ${SOURCES_JS})
source_group(javascript/3rdparty FILES ${SOURCES_JS_3rdparty})
source_group(javascript/dtdsource FILES ${SOURCES_JS_dtdsource})
source_group(javascript/elementtypes FILES ${SOURCES_JS_elementtypes})

set_property(TARGET corinthia PROPERTY FOLDER consumers)
