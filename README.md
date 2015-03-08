# ofxDeinterlace

ofxDeinterlace is simple line averaging [deinterlacer](http://en.wikipedia.org/wiki/Deinterlacing) for openFrameworks. This addon use GLSL for deinterlace process. GLSL code refer the discussion topics below.

- [Re: 1080i interlacing (Apple Mailing Lists)](http://lists.apple.com/archives/quartzcomposer-dev/2008/Aug/msg00157.html)

## How to use

You just send video texture reference to the addon in setup() function.

```
video.loadMovie("1080i.mov");
video.play();
deinterlace = new ofxDeinterlace(video.getTextureReference());
```

to draw interlaced texture just call draw() method of addon.

```
deinterlace->draw();
```

## License

ofxDeinterlace is distributed under the MIT License.
