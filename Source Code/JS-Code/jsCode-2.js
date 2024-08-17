function drawLine(x1, y1, x2, y2) {
    ctx.beginPath();
    ctx.moveTo(ROOT_XCOR+x1, ROOT_YCOR+y1);
    ctx.lineTo(ROOT_XCOR+x2, ROOT_YCOR+y2);
    ctx.strokeStyle = LINE_COLOR;
    ctx.lineWidth = LINE_WIDTH;
    ctx.stroke();
}

function drawCircle(x,y,radius,color){
    ctx.beginPath();
    ctx.arc(x, y, radius, 0, 2 * Math.PI);
    ctx.fillStyle = color;
    ctx.fill();
    ctx.strokeStyle = color;
    ctx.stroke();
}

function drawNode(num, x, y, color) {
    drawCircle(ROOT_XCOR+x,ROOT_YCOR+y,OUTER_RAD,color);
    drawCircle(ROOT_XCOR+x,ROOT_YCOR+y,INNER_RAD,BG_COLOR);
    ctx.font = '20px Arial';
    ctx.fillStyle = 'white';
    ctx.textAlign = 'center';
    ctx.textBaseline = 'middle';
    ctx.fillText(num, x+ROOT_XCOR, y+ROOT_YCOR);
}