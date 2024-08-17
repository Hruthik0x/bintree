document.addEventListener('DOMContentLoaded', () => {
const canvas = document.getElementById('myCanvas');
const ctx = canvas.getContext('2d');
const bg_color = "#161617";const theme_color = "#007bff";
const outer_rad = 25;
const inner_rad = 21;
const line_width = 4;
function drawLine(x1, y1, x2, y2) {
ctx.beginPath();
ctx.moveTo(x1, y1);
ctx.lineTo(x2, y2);
ctx.strokeStyle = theme_color;
ctx.lineWidth = line_width;ctx.stroke();
}
function draw_circle(x,y,radius,color){
ctx.beginPath();
ctx.arc(x, y, radius, 0, 2 * Math.PI);
ctx.fillStyle = color;ctx.fill();
ctx.strokeStyle = color;ctx.stroke();
}
function node(x, y,text) {
draw_circle(x,y,outer_rad,theme_color);
draw_circle(x,y,inner_rad,bg_color);
ctx.font = '20px Arial';
ctx.fillStyle = 'white';
ctx.textAlign = 'center';
ctx.textBaseline = 'middle';
ctx.fillText(text, x, y);
}

node(940,547,'48');


ctx.font = "24px Arial";
ctx.fillStyle = "white";
ctx.fillText(" hi guys", 940, 487);
});