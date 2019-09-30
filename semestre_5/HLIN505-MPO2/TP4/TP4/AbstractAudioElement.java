package TP4;

import java.io.File;

public abstract class AbstractAudioElement implements ElementAudio{
	private File file;
	private Sring fileLocation;
	private Strine title;

	@Override
	public String getNom(){
		return this.title;
	}
	
	@Override
	public String getFileLocation(){
		return fileLocation;
	}
	public AbstractAudioElement(String title, String fileLocation){
		this.title = title;
		this.fileLocation = fileLocation;
		file = new File(fileLocation);
	}
	public File getFichier(){
		return file;
	}
	public void s
}
