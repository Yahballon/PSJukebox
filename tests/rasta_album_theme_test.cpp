// SPDX-License-Identifier: GPL-3.0-or-later
#include "../native/rasta_album_theme.hpp"
#include <cassert>
#include <set>
#include <cstdio>
int main(){
 const auto first=jukebox::rasta_album_theme("/Music/Legend");
 assert(first.stripes==jukebox::rasta_album_theme("/Music/Legend").stripes);
 std::set<uint32_t> accents;
 const char* keys[]={"/Music/Legend","/Music/Exodus","/Music/Kaya",
  "/Music/36 Chambers","/Music/Discovery","/Music/Doggystyle","/Music/Greatest Hits"};
 for(auto key:keys){
  const auto x=jukebox::rasta_album_theme(key);
  accents.insert(x.accent);
  std::set<uint32_t> rgb(x.stripes.begin(),x.stripes.end());
  assert(rgb.size()==3&&rgb.count(x.green)&&rgb.count(x.gold)&&rgb.count(x.red));
 }
 assert(accents.size()>1);
 puts("PASS stable randomized Rasta palettes by album");
}
