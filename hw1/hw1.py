import BMPImg;

def main():
	bmpimg = BMPImg.BMPImg();
	bmpimg.loadPic('liver.bmp');
	bmpimg.printHeader();
	bmpimg.RGB2Y();
	bmpimg.storePic('test.bmp');

if __name__ == '__main__':
	main();