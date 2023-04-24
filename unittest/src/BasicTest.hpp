// Copyright © 2023 Tobias Erbsland. Web: https://erbsland.dev
// Copyright © 2023 EducateIT GmbH. Web: https://educateit.ch
//
// This program is free software: you can redistribute it and/or modify it under the terms of the
// GNU Lesser General Public License as published by the Free Software Foundation, either
// version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License along with this program.
// If not, see <https://www.gnu.org/licenses/>.
#pragma once


#include <erbsland/unittest/UnitTest.hpp>

#include <ExampleLib.hpp>


using erbsland::ExampleLib;


TESTED_TARGETS(ExampleLib)
class BasicTest : public el::UnitTest {
public:
    TESTED_TARGETS(getMagicWord)
    void testMagic() {
        auto exampleLib = ExampleLib{};
        REQUIRE(exampleLib.getMagicWord() == "Magic");
    }

    TESTED_TARGETS(getName getNameLength setName)
    void testNameSetAndGet() {
        auto exampleLib = ExampleLib{};
        REQUIRE(exampleLib.getName().empty());
        REQUIRE(exampleLib.getNameLength() == 0);
        exampleLib.setName("Joe");
        REQUIRE(exampleLib.getName() == "Joe");
        REQUIRE(exampleLib.getNameLength() == 3);
        exampleLib.setName("Anna");
        REQUIRE(exampleLib.getName() == "Anna");
        REQUIRE(exampleLib.getNameLength() == 4);
    }

    TESTED_TARGETS(setName isNamePalindrome)
    void testIsNamePalindrome() {
        auto exampleLib = ExampleLib{};
        exampleLib.setName("joe");
        REQUIRE_FALSE(exampleLib.isNamePalindrome());
        exampleLib.setName("anna");
        REQUIRE(exampleLib.isNamePalindrome());
        exampleLib.setName("Joe");
        REQUIRE_FALSE(exampleLib.isNamePalindrome());
        exampleLib.setName("Anna");
        REQUIRE(exampleLib.isNamePalindrome());
        exampleLib.setName({});
        REQUIRE_FALSE(exampleLib.isNamePalindrome());
    }

};

