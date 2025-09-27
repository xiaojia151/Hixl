# ----------------------------------------------------------------------------
# This program is free software, you can redistribute it and/or modify.
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.14)
project(CANN-OPS-DXL)

# 外部传参
option(ENABLE_TEST "Enable test" OFF)
option(ASCEND_3RD_LIB_PATH "Acend third party library path" "./output/third_party")
include(cmake/variables.cmake)
include(CMakePackageConfigHelpers)
include(cmake/build_type.cmake)
# 第三方软件包
include(cmake/find_3rd_party_packages.cmake)
# CANN软件包
include(cmake/find_common_cann_packages.cmake)
include(cmake/intf_pub_linux.cmake)
include(cmake/test_utils.cmake)
include(cmake/python_depends.cmake)
if (ENABLE_TEST)
    include(${PROJECT_SOURCE_DIR}/cmake/third_party/gtest.cmake)
    include(cmake/stub_test_mode_cann_packages.cmake)
else ()
    include(cmake/find_release_mode_cann_packages.cmake)
endif()

add_custom_target(select_targets)
if (ENABLE_TEST)
    add_subdirectory(tests)
    add_dependencies(select_targets llm_datadist_wrapper
                                    metadef_wrapper
                                    llm_datadist_test)
else ()
    add_subdirectory(src)
    add_dependencies(select_targets llm_datadist
                                    llm_datadist_python)
endif()

# install
set(ARCH_LINX_PATH "${CMAKE_SYSTEM_PROCESSOR}-linux")

if (NOT ENABLE_TEST)
    install(TARGETS llm_datadist
        LIBRARY DESTINATION ${ARCH_LINX_PATH}/lib64 OPTIONAL COMPONENT packages EXCLUDE_FROM_ALL
        ARCHIVE DESTINATION ${ARCH_LINX_PATH}/lib64 OPTIONAL COMPONENT packages EXCLUDE_FROM_ALL
        RUNTIME DESTINATION ${ARCH_LINX_PATH}/bin OPTIONAL COMPONENT packages EXCLUDE_FROM_ALL
    )

    install(DIRECTORY ${DXL_CODE_DIR}/include/
        DESTINATION ${ARCH_LINX_PATH}/include
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_READ GROUP_READ
        COMPONENT packages EXCLUDE_FROM_ALL
        PATTERN "include/OWNERS" EXCLUDE
    )
endif()

set(version_info "${ASCEND_INSTALL_PATH}/runtime/version.info")
set(install_script_dir "${CMAKE_CURRENT_BINARY_DIR}/install_scripts/")

add_custom_target(generate_install_script_air ALL
    COMMAND rm -rf ${install_script_dir}
    COMMAND cp -rf ${ASCEND_INSTALL_PATH}/toolkit/tools/ascend_project/open_install_scripts ${install_script_dir}
    COMMAND chmod -R u+w ${install_script_dir}
    COMMAND echo "base_package=runtime\;compiler" > ${install_script_dir}/version.info
    COMMAND echo "backup_dir=air" >> ${install_script_dir}/version.info
    COMMAND grep -iE "'^(version|version_dir)='" ${version_info} >> ${install_script_dir}/version.info
)

install(DIRECTORY ${install_script_dir}
    DESTINATION . OPTIONAL
    FILE_PERMISSIONS OWNER_EXECUTE OWNER_READ GROUP_READ
    COMPONENT . EXCLUDE_FROM_ALL
)

set(CPACK_COMPONENTS_ALL ".;packages")
set(CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION "CPack air project")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CPack air project")
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/package)
set(CPACK_PACKAGE_FILE_NAME "CANN-ops-dxl-linux.${CMAKE_SYSTEM_PROCESSOR}.run")
set(CPACK_GENERATOR External)
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_EXTERNAL_ENABLE_STAGING TRUE)
set(CPACK_EXTERNAL_PACKAGE_SCRIPT ${ASCEND_INSTALL_PATH}/toolkit/tools/op_project_templates/ascendc/customize/cmake/makeself.cmake)
set(CPACK_EXTERNAL_BUILT_PACKAGES ${CPACK_PACKAGE_DIRECTORY}/_CPack_Packages/Linux/External/${CPACK_PACKAGE_FILE_NAME}/${CPACK_PACKAGE_FILE_NAME})
include(CPack)

