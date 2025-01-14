/*

   ____                               ____      ___ ____       ____  ____      ___
  6MMMMb                              `MM(      )M' `MM'      6MMMMb\`MM(      )M'
 8P    Y8                              `MM.     d'   MM      6M'    ` `MM.     d'
6M      Mb __ ____     ____  ___  __    `MM.   d'    MM      MM        `MM.   d'
MM      MM `M6MMMMb   6MMMMb `MM 6MMb    `MM. d'     MM      YM.        `MM. d'
MM      MM  MM'  `Mb 6M'  `Mb MMM9 `Mb    `MMd       MM       YMMMMb     `MMd
MM      MM  MM    MM MM    MM MM'   MM     dMM.      MM           `Mb     dMM.
MM      MM  MM    MM MMMMMMMM MM    MM    d'`MM.     MM            MM    d'`MM.
YM      M9  MM    MM MM       MM    MM   d'  `MM.    MM            MM   d'  `MM.
 8b    d8   MM.  ,M9 YM    d9 MM    MM  d'    `MM.   MM    / L    ,M9  d'    `MM.
  YMMMM9    MMYMMM9   YMMMM9 _MM_  _MM_M(_    _)MM_ _MMMMMMM MYMMMM9 _M(_    _)MM_
            MM
            MM
           _MM_

  Copyright (c) 2018, Kenneth Troldal Balslev

  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
  - Neither the name of the author nor the
    names of any contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#ifndef OPENXLSX_XLDRAWING_HPP
#define OPENXLSX_XLDRAWING_HPP

// ===== External Includes ===== //
#include <cstdint>      // uint8_t, uint16_t, uint32_t
#include <ostream>      // std::basic_ostream

// ===== OpenXLSX Includes ===== //
#include "OpenXLSX-Exports.hpp"
// #include "XLDocument.hpp"
#include "XLException.hpp"
#include "XLXmlData.hpp"
#include "XLXmlFile.hpp"


namespace OpenXLSX
{
		// <v:fill o:detectmouseclick="t" type="solid" color2="#00003f"/>
		// <v:shadow on="t" obscured="t" color="black"/>
		// <v:stroke color="#3465a4" startarrow="block" startarrowwidth="medium" startarrowlength="medium" joinstyle="round" endcap="flat"/>
		// <v:path o:connecttype="none"/>
		// <v:textbox style="mso-direction-alt:auto;mso-fit-shape-to-text:t;">
		// 	<div style="text-align:left;"/>
		// </v:textbox>

    // NOTE: numerical values of XLShapeTextVAlign and XLShapeTextHAlign are shared with the same alignments from XLAlignmentStyle (XLStyles.hpp)
    enum class XLShapeTextVAlign : uint8_t {
        Center           =   3, // value="center",           both
        Top              =   4, // value="top",              vertical only
        Bottom           =   5, // value="bottom",           vertical only
        Invalid          = 255  // all other values
    };

    enum class XLShapeTextHAlign : uint8_t {
        Left             =   1, // value="left",             horizontal only
        Right            =   2, // value="right",            horizontal only
        Center           =   3, // value="center",           both
        Invalid          = 255  // all other values
    };

    /**
     * @brief An encapsulation of a shape client data element x:ClientData
     */
    // class OPENXLSX_EXPORT XLShapeClientData
    // {
    // public:    // ---------- Public Member Functions ---------- //
    //     /**
    //      * @brief
    //      */
    //     XLShapeClientData();
    // 
    //     /**
    //      * @brief Constructor. New items should only be created through an XLShape object.
    //      * @param node An XMLNode object with the line XMLNode. If no input is provided, a null node is used.
    //      */
    //     explicit XLShapeClientData(const XMLNode& node);
    // 
    //     /**
    //      * @brief Copy Constructor.
    //      * @param other Object to be copied.
    //      */
    //     XLShapeClientData(const XLShapeClientData& other) = default;
    // 
    //     /**
    //      * @brief Move Constructor.
    //      * @param other Object to be moved.
    //      */
    //     XLShapeClientData(XLShapeClientData&& other) noexcept = default;
    // 
    //     /**
    //      * @brief
    //      */
    //     ~XLShapeClientData() = default;
    // 
    //     /**
    //      * @brief Copy assignment operator.
    //      * @param other Right hand side of assignment operation.
    //      * @return A reference to the lhs object.
    //      */
    //     XLShapeClientData& operator=(const XLShapeClientData& other) = default;
    // 
    //     /**
    //      * @brief Move assignment operator.
    //      * @param other Right hand side of assignment operation.
    //      * @return A reference to lhs object.
    //      */
    //     XLShapeClientData& operator=(XLShapeClientData&& other) noexcept = default;
    // 
    //     /**
    //      * @brief Getter functions
    //      */
    //     std::string objectType() const; // attribute ObjectType, value "Note"
    //     bool moveWithCells() const;     // element x:MoveWithCells - true = present or lowercase node_pcdata "true", false = not present or lowercase node_pcdata "false"
    //     bool sizeWithCells() const;     // element x:SizeWithCells - logic as in MoveWithCells
    //     std::string anchor() const;     // element x:Anchor - Example node_pcdata: "3, 23, 0, 0, 4, 25, 3, 5" - no idea what any number means - TBD
    //     bool autoFill() const;          // element x:AutoFill - logic as in MoveWithCells
    //     XLShapeTextVAlign textVAlign() const;   // element x:TextVAlign - Top, ???
    //     XLShapeTextHAlign textHAlign() const;   // element x:TextHAlign - Left, ???
    //     uint32_t row() const;           // element x:Row, 0-indexed row of cell to which this shape is linked
    //     uint16_t column() const;        // element x:Column, 0-indexed column of cell to which this shape is linked
    // 
    //     /**
    //      * @brief Setter functions
    //      */
    //     bool setObjectType(std::string newObjectType);
    //     bool setMoveWithCells(bool set);
    //     bool setSizeWithCells(bool set);
    //     bool setAnchor(std::string newAnchor);
    //     bool setAutoFill(bool set);
    //     bool setTextVAlign(XLShapeTextVAlign newTextVAlign);
    //     bool setTextHAlign(XLShapeTextHAlign newTextHAlign);
    //     bool setRow(uint32_t newRow);
    //     bool setColumn(uint16_t newColumn);
    // 
    //     // /**
    //     //  * @brief Return a string summary of the line properties
    //     //  * @return string with info about the line object
    //     //  */
    //     // std::string summary() const;
    // 
    // private:                                         // ---------- Private Member Variables ---------- //
    //     std::unique_ptr<XMLNode> m_ClientDataNode;   /**< An XMLNode object with the x:ClientData item */
    //  };


    class OPENXLSX_EXPORT XLShape {
        friend class XLDrawing;    // for access to m_shapeNode in XLDrawing::addShape
    public:    // ---------- Public Member Functions ---------- //
        /**
         * @brief
         */
        XLShape();

        /**
         * @brief Constructor. New items should only be created through an XLStyles object.
         * @param node An XMLNode object with the styles item. If no input is provided, a null node is used.
         */
        explicit XLShape(const XMLNode& node);

        /**
         * @brief Copy Constructor.
         * @param other Object to be copied.
         */
        XLShape(const XLShape& other) = default;

        /**
         * @brief Move Constructor.
         * @param other Object to be moved.
         */
        XLShape(XLShape&& other) noexcept = default;

        /**
         * @brief
         */
        ~XLShape() = default;

        /**
         * @brief Copy assignment operator.
         * @param other Right hand side of assignment operation.
         * @return A reference to the lhs object.
         */
        XLShape& operator=(const XLShape& other);

        /**
         * @brief Move assignment operator.
         * @param other Right hand side of assignment operation.
         * @return A reference to lhs object.
         */
        XLShape& operator=(XLShape&& other) noexcept = default;

        /**
         * @brief Getter functions
         */
        // std::string shapeId() const;   // v:shape attribute id - shape_#?  _x0000_s10##?
        // std::string fillColor() const; // v:shape attribute fillcolor, #<3 byte hex code>, e.g. #ffffc0
        // bool stroked() const;          // v:shape attribute stroked "t" ("f"?)
        // std::string type() const;      // v:shape attribute type, link to v:shapetype attribute id
        // bool allowInCell() const;      // v:shape attribute o:allowincell "f"
        // std::string style() const;     // v:shape attribute style
        // // Example: style="position:absolute;margin-left:258pt;margin-top:0pt;width:81.65pt;height:50.9pt;mso-wrap-style:none;v-text-anchor:middle;visibility:hidden">
        // // ==> should probably create a subclass XLShapeStyle to further disassemble this attribute

        // XLShapeShadow& shadow();          // v:shape subnode v:shadow
        // XLShapeFill& fill();              // v:shape subnode v:fill
        // XLShapeStroke& stroke();          // v:shape subnode v:stroke
        // XLShapePath& path();              // v:shape subnode v:path
        // XLShapeTextbox& textbox();        // v:shape subnode v:textbox
        // XLShapeClientData& clientData();  // v:shape subnode x:ClientData

        /**
         * @brief Setter functions
         * @param value that shall be set
         * @return true for success, false for failure
         */
        // bool setShapeId(std::string newShapeId);
        // bool setFillColor(std::string newFillColor);
        // bool setStroked(bool set);
        // bool setType(std::string newType);
        // bool setAllowInCell(bool set);
        // bool setStyle(std::string newStyle);

    private:                                         // ---------- Private Member Variables ---------- //
        std::unique_ptr<XMLNode> m_shapeNode;        /**< An XMLNode object with the v:shape item */
    };

    /**
     * @brief The XLDrawing class is the base class for worksheet comments
     */
    class OPENXLSX_EXPORT XLDrawing : public XLXmlFile
    {
        friend class XLWorksheet;   // for access to XLXmlFile::getXmlPath
    public:
        /**
         * @brief Constructor
         */
        XLDrawing() : XLXmlFile(nullptr) {};

        /**
         * @brief The constructor.
         * @param xmlData the source XML of the comments file
         */
        XLDrawing(XLXmlData* xmlData);

        /**
         * @brief The copy constructor.
         * @param other The object to be copied.
         * @note The default copy constructor is used, i.e. only shallow copying of pointer data members.
         */
        XLDrawing(const XLDrawing& other) = default;

        /**
         * @brief
         * @param other
         */
        XLDrawing(XLDrawing&& other) noexcept = default;

        /**
         * @brief The destructor
         * @note The default destructor is used, since cleanup of pointer data members is not required.
         */
        ~XLDrawing() = default;

        /**
         * @brief Assignment operator
         * @return A reference to the new object.
         * @note The default assignment operator is used, i.e. only shallow copying of pointer data members.
         */
        XLDrawing& operator=(const XLDrawing&) = default;

        /**
         * @brief
         * @param other
         * @return
         */
        XLDrawing& operator=(XLDrawing&& other) noexcept = default;

    private: // helper functions with repeating code
        XMLNode firstShapeNode() const;
        XMLNode lastShapeNode() const;
        XMLNode shapeNode(uint32_t index) const;

    public:

        uint32_t shapeCount() const;

        XLShape shape(uint32_t index) const;

        bool deleteShape(uint32_t index);

        uint32_t createShape(const XLShape& shapeTemplate = XLShape());

        /**
         * @brief Print the XML contents of this XLDrawing instance using the underlying XMLNode print function
         */
        void print(std::basic_ostream<char>& ostr) const;

    private:
        uint32_t m_shapeCount{0};
        uint32_t m_lastAssignedShapeId{0};
        std::string m_defaultShapeTypeId{};
    };
}    // namespace OpenXLSX

#endif    // OPENXLSX_XLDRAWING_HPP
