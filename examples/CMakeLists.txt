#
# Advanced Simulation Library <http://asl.org.il>
# 
# Copyright 2015 Avtech Scientific <http://avtechscientific.com>
#
#
# This file is part of Advanced Simulation Library (ASL).
#
# ASL is free software: you can redistribute it and/or modify it
# under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, version 3 of the License.
#
# ASL is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with ASL. If not, see <http://www.gnu.org/licenses/>.
#


add_subdirectory(flow)
add_subdirectory(elastic)
add_subdirectory(levelSet)
add_subdirectory(jumpingObjects)
add_subdirectory(heatTransfer)
add_subdirectory(massTransferSM)

# Disable this for now, until we decide to distribute the input data along with ASL
# install(DIRECTORY ${CMAKE_SOURCE_DIR}/input_data DESTINATION ${CMAKE_INSTALL_DOCDIR})