# Filter/less

## Problem to Solve

Implement the functions in helpers.c such that a user can apply grayscale, sepia, reflection, or blur filters to their images.
- The function grayscale should take an image and turn it into a black-and-white version of the same image.

### The grayscale algorithm
The “grayscale” filter is a mainstay of the image filtering world: it takes (potentially quite colorful) images and converts them to “black-and-white”, as though the image were taken before the popularization of color photography. How does something like that work?
- Recall that if the red, green, and blue values are all set to ```0x00``` (hexadecimal for ```0```), then the pixel is black. And if all values are set to ```0xff``` (hexadecimal for ```255```), then the pixel is white. So long as the red, green, and blue values are all equal, the result will be varying shades of gray along the black-white spectrum, with higher values meaning lighter shades (closer to white) and lower values meaning darker shades (closer to black).
- So to convert a pixel to grayscale, you just need to make sure the red, green, and blue values are all the same value. But how do you know what value to make them? Well, it’s probably reasonable to expect that if the original red, green, and blue values were all pretty high, then the new value should also be pretty high. And if the original values were all low, then the new value should also be low.
- In fact, to ensure each pixel of the new image still has the same general brightness or darkness as the old image, you can take the average of the red, green, and blue values to determine what shade of grey to make the new pixel.

If you apply the above algorithm to each pixel in the image, the result will be an image converted to grayscale.

### The sepia algorithm

Most image editing programs support a “sepia” filter, which gives images an old-timey feel by making the whole image look a bit reddish-brown.

- An image can be converted to sepia by taking each pixel, and computing new red, green, and blue values based on the original values of the three.
- There are a number of algorithms for converting an image to sepia, but for this problem, we’ll ask you to use the following algorithm. For each pixel, the sepia color values should be calculated based on the original color values per the below.

```
sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
```

- Of course, the result of each of these formulas may not be an integer, but each value could be rounded to the nearest integer. It’s also possible that the result of the formula is a number greater than 255, the maximum value for an 8-bit color value. In that case, the red, green, and blue values should be capped at 255. As a result, we can guarantee that the resulting red, green, and blue values will be whole numbers between 0 and 255, inclusive.

If you apply the above algorithm to each pixel in the image, the result will be an image converted to sepia.

### The reflect algorithm

Some more adventurous filters might go further than merely editing the pixels in place; they might move the pixels around the image. Reflecting an image, for example, is a filter where the resulting image is what you would get by placing the original image in front of a mirror.

- Any pixels on the left side of the image should end up on the right, and vice versa.
- Note that all of the original pixels of the original image will still be present in the reflected image, it’s just that those pixels may have been rearranged to be in a different place in the image.

If you apply the above algorithm to each pixel in the image, the result should look like a mirror image of the original.

### The blur algorithm

There are a number of ways to create the effect of blurring or softening an image, giving the resulting picture a hazy, dreamlike feeling (or perhaps just the feeling of having lost your glasses). For this problem, we’ll use the “box blur,” which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.

If you apply the above algorithm to each pixel in the image, the result should look like a blurry, out-of-focus version of the original.

---
Based on: [filter](https://www.youtube.com/watch?v=K0v9byp9jd0&list=PLhQjrBD2T3837jmUt0ep7Tpmnxdv9NVut "https://www.youtube.com/watch?v=K0v9byp9jd0&list=PLhQjrBD2T3837jmUt0ep7Tpmnxdv9NVut")
