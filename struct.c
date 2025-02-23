#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct Image{
char name[30], file_format[10];
int width, height, depth, number_of_channels;

};
void displayImage(struct Image image){
  printf("Image name         :%s\n",image.name);
  printf("Image File Format  :%s\n",image.file_format);
  printf("Image width        :%d\n",image.width);
  printf("Image height       :%d\n",image.height);
  printf("Image depth        :%d\n",image.depth);
  printf("Number of channels :%d\n",image.number_of_channels);
  printf("\n\n\n");
}

struct Image copyimage(struct Image sourceImage, struct Image destinationImage){
  strcpy(destinationImage.name,sourceImage.name);
  strcpy(destinationImage.file_format,sourceImage.file_format);
  
  destinationImage.width = sourceImage.width;
  destinationImage.height = sourceImage.height;
  destinationImage.depth  = sourceImage.depth;
  destinationImage.number_of_channels = sourceImage.number_of_channels;
  return destinationImage;
}

struct Image resize(struct Image sourceImage, int ratio){
  sourceImage.width *= ratio;
  sourceImage.height *= ratio;

  return sourceImage;
}


int main(){

  int ratio;
  struct Image myImage;
  strcpy(myImage.name, "myImage");
  strcpy(myImage.file_format,"jpg");
  myImage.width = 512;
  myImage.height=512;
  myImage.depth=8;
  myImage.number_of_channels=3;

  printf("This is the source image details..\n\n");
  displayImage(myImage);

  struct Image newImage;

  newImage = copyimage(myImage, newImage);

  printf("This is the new image details..\n\n");
  displayImage(newImage);

  printf("Enter ratio to size image:");
  scanf("%d",&ratio);

  newImage=resize(newImage,ratio);
  printf("This is the sized image details..\n\n");
  displayImage(newImage);
  
  
  
  return 0;
}
