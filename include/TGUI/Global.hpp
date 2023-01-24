/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2023 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TGUI_GLOBAL_HPP
#define TGUI_GLOBAL_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <TGUI/Config.hpp>
#include <TGUI/Exception.hpp>
#include <TGUI/Duration.hpp>
#include <TGUI/Font.hpp>
#include <TGUI/String.hpp>
#include <TGUI/Filesystem.hpp>

#if !TGUI_EXPERIMENTAL_USE_STD_MODULE
    #include <cstdint>
    #include <string>
    #include <memory>

    #ifdef TGUI_DEBUG
        #include <iostream>
    #endif
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Namespace that contains all TGUI functions and classes
namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Create a unique_ptr containing an uninitialized array
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(__cpp_lib_smart_ptr_for_overwrite) && (__cpp_lib_smart_ptr_for_overwrite >= 202002L)
    template <typename T>
    const auto MakeUniqueForOverwrite = std::make_unique_for_overwrite<T>;
#else
    template <typename T>
    TGUI_NODISCARD std::unique_ptr<T> MakeUniqueForOverwrite(const std::size_t size)
    {
        return std::unique_ptr<T>(new typename std::remove_extent_t<T>[size]);
    }
#endif


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets the default text size for all widgets created after calling the function
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void setGlobalTextSize(unsigned int textSize);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves the default text size used for all new widgets
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_NODISCARD TGUI_API unsigned int getGlobalTextSize();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets the double-click time for the mouse
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void setDoubleClickTime(Duration duration);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves the double-click time for the mouse
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_NODISCARD TGUI_API Duration getDoubleClickTime();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets a new resource path
    ///
    /// This pathname is placed in front of every filename that is used to load a resource.
    ///
    /// @param path  New resource path
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void setResourcePath(const Filesystem::Path& path);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Sets a new resource path
    ///
    /// This pathname is placed in front of every filename that is used to load a resource.
    ///
    /// @param path  New resource path
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void setResourcePath(const String& path);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Returns the resource path
    ///
    /// This pathname is placed in front of every filename that is used to load a resource.
    ///
    /// @return The current resource path
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_NODISCARD TGUI_API const Filesystem::Path& getResourcePath();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Changes the blink rate of the cursor in edit fields such as EditBox and TextArea
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API void setEditCursorBlinkRate(Duration blinkRate);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Returns the blink rate of the cursor in edit fields such as EditBox and TextArea
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_NODISCARD TGUI_API Duration getEditCursorBlinkRate();


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Opens a file and reads its contents into memory
    ///
    /// @param filename  Path to the file to read
    /// @param fileSize  Size of the file, to be filled in by this function if loading succeeds (untouched on failure)
    ///
    /// @return Bytes read from the file, or nullptr if loading failed (or file was empty)
    ///
    /// On android, the file will be read using the asset manager if a relative filename is passed.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_NODISCARD TGUI_API std::unique_ptr<std::uint8_t[]> readFileToMemory(const String& filename, std::size_t& fileSize);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Opens a file and writes the given contents to it
    ///
    /// @param filename    Path to the file to write
    /// @param textToWrite Contents to be written to the file
    ///
    /// @return True on success, false if opening or writing to the file failed
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool writeFile(const String& filename, const std::stringstream& textToWrite);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Opens a file and writes the given contents to it
    ///
    /// @param filename    Path to the file to write
    /// @param textToWrite Contents to be written to the file
    ///
    /// @return True on success, false if opening or writing to the file failed
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TGUI_API bool writeFile(const String& filename, CharStringView textToWrite);


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_GLOBAL_HPP

