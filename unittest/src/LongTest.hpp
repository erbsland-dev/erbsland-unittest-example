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

#include <string>
#include <sstream>


using erbsland::ExampleLib;


TESTED_TARGETS(ExampleLib)
class LongTest : public el::UnitTest {
public:
    static constexpr std::size_t size = 6;

    bool result{};
    std::string name{};

    std::string additionalErrorMessages() override {
        try {
            auto text = std::ostringstream{};
            text << "result = " << std::boolalpha << result << "\n"
                 << "name = \"" << name << "\"\n"
                 << "expected result = " << std::boolalpha << expectedResult() << "\n";
            return text.str();
        } catch(...) {
            return {"Unexpected Exception"};
        }
    }

    [[nodiscard]] auto expectedResult() noexcept -> bool {
        for (std::size_t i = 0; i < size/2; ++i) {
            if (name[i] != name[size - i - 1]) {
                return false;
            }
        }
        return true;
    }

    TAGS(long-test)
    SKIP_BY_DEFAULT()
    TESTED_TARGETS(setName isNamePalindrome)
    void testIsNamePalindromeBruteForce() {
        auto exampleLib = ExampleLib{};
        name = std::string(size, 'a');
        std::size_t count{0};
        while (name[size-1] != 'z') {
            exampleLib.setName(name);
            result = exampleLib.isNamePalindrome();
            REQUIRE(result == expectedResult());
            for (std::size_t i = 0; i < size; ++i) {
                if (name[i] < 'z') {
                    name[i] += 1;
                    break;
                } else {
                    name[i] = 'a';
                }
            }
            if (count % 1'000'000 == 0) {
                auto text = std::ostringstream{};
                text << "Testing name " << count << ": " << name;
                consoleWriteLine(text.str());
            }
            count += 1;
        }
    }
};

