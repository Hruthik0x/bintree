document.addEventListener('DOMContentLoaded', () => {

    const canvas = document.getElementById('myCanvas');
    const ctx = canvas.getContext('2d');const OUTER_RAD = 25;
const INNER_RAD = 21;
const LINE_WIDTH = 4;
const DEFAULT_TREE_COLOR = "#007bff";
const LINE_COLOR = "#161617";
const BG_COLOR = "#404040";
const ROOT_XCOR = 940;
const ROOT_YCOR = 350;
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
}drawLine(-60, 80, 0, 0);
drawLine(120, 80, 60, 160);
drawLine(240, 160, 180, 240);
drawLine(240, 160, 300, 240);
drawLine(120, 80, 240, 160);
drawLine(120, 80, 0, 0);
drawNode(8, 0, 0, "#000000");
drawNode(5, -60, 80, "#000000");
drawNode(15, 60, 160, "#000000");
drawNode(17, 120, 80, "#ff0000");
drawNode(18, 180, 240, "#ff0000");
drawNode(25, 240, 160, "#000000");
drawNode(40, 300, 240, "#ff0000");

});
