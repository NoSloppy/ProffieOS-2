The spectrum song preset is a little more complicated. First you need to obtain the spectrum song video, then export the audio from that as 16-bit PCM, 44100Hz, Mono. Save that has "humm.wav" in your font directory. Second, you must must compile the videotoblc program. It comes with ProffieOS, but is a separate program. videotoblc also relies on having "ffmpeg" installed, so if you don't have that, it's not going to work. Once you have videotblc and ffmpeg installed, you should be able to run "videotblc spectrum_song.mp4 >humm.blc" to get a BLC file. Put that file in your font directory, and then everything should work as in my demo.


Using videotoblc
MacOS:
pre-req: Developer tools installed.
  `xcode-select --install`
install Homebrew
`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
`brew install ffmpeg`

cd to videotoblc directory.
make
PATH=/usr/local/bin:. ./videotoblc spectrum_song.mp4 >humm.blc
unless PATH is already established

Usage:
   StyleNormalPtr<FromHumFileStyle<170,0, 25,1>, WHITE, 300, 800>(),
  
PATH=/usr/local/bin:. ./videotoblc spectrum_song.mp4 >humm.blc
Crop video and export 480x360 25fps if 4:3 source 