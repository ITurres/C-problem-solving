let height = 8;

function drawPyramid(height) {
  console.log(height);

  for (let row = 1; row < height; row++) {
    for (let j = 1; j < height; j++) {
      console.log("#");
    }
    console.log(" ");
  }
}

drawPyramid(height);
