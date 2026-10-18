// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include <array>
#include <cstdint>
#include <string_view>
namespace jukebox {
// Random-looking yet deterministic colors for an album identity.
// Keeps its theme across launches and never flickers between render frames.
struct RastaAlbumTheme {
 uint32_t green,gold,red,accent,backdrop;
 std::array<uint32_t,3> stripes;
};
inline RastaAlbumTheme rasta_album_theme(std::string_view key){
 uint32_t h=2166136261u;
 for(unsigned char c:key){h^=c;h*=16777619u;}
 h^=h>>16;
 constexpr uint32_t greens[]={0x20d78b,0x44e39d,0x38d483,0x16c990,0x72da9b,0x21c87d};
 constexpr uint32_t golds[]={0xffcd39,0xfbdc64,0xffc44b,0xf5d568,0xffe184,0xf3ba37};
 constexpr uint32_t reds[]={0xff7964,0xf97768,0xf46b61,0xff8a73,0xea665a,0xff7460};
 constexpr uint32_t darks[]={0x09291e,0x123325,0x17271a,0x0b2e2d,0x232c1d,0x1b2427};
 const uint32_t green=greens[h%6u],gold=golds[(h>>7)%6u],red=reds[(h>>14)%6u];
 const std::array<uint32_t,3> colors={green,gold,red};
 const unsigned rot=(h>>22)%3u;
 return {green,gold,red,colors[(h>>17)%3u],darks[(h>>11)%6u],
         {colors[rot],colors[(rot+1u)%3u],colors[(rot+2u)%3u]}};
}
} // namespace jukebox
