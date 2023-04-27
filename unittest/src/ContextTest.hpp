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

#include <sstream>


using erbsland::ExampleLib;


TESTED_TARGETS(ExampleLib)
class ContextTest : public el::UnitTest {
public:
    ExampleLib exampleLib{};

    auto additionalErrorMessages() -> std::string override {
        try {
            auto text = std::ostringstream{};
            text << "ExampleLib:\n"
                 << "    getName() = \"" << exampleLib.getName() << "\"\n"
                 << "    getNameLength() = " << exampleLib.getNameLength() << "\n";
            return text.str();
        } catch(...) {
            return {"Unexpected Exception"};
        }
    }

    void setAndVerifyName(const std::string &name) {
        exampleLib.setName(name);
        auto expectedSize = name.size();
        REQUIRE(exampleLib.getName() == name);
        REQUIRE(exampleLib.getNameLength() == expectedSize);
    }

    void setAndVerifyName_error(const std::string &name) {
        // This method just demonstrates what happens when an error occurs.
        exampleLib.setName(name);
        auto expectedSize = name.size();
        REQUIRE(exampleLib.getName() == name);
        REQUIRE_FALSE(exampleLib.getNameLength() == expectedSize);
    }

    TESTED_TARGETS(getName getNameLength setName)
    void testNameSetAndGet() {
        WITH_CONTEXT(setAndVerifyName({}));
        WITH_CONTEXT(setAndVerifyName("joe"));
        WITH_CONTEXT(setAndVerifyName("anna"));
        WITH_CONTEXT(setAndVerifyName("Joe"));
        WITH_CONTEXT(setAndVerifyName("Anna"));
        WITH_CONTEXT(setAndVerifyName("Peter"));
        WITH_CONTEXT(setAndVerifyName_error("Lisa"));
    }
};

