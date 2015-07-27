<GameProjectFile>
  <PropertyGroup Type="Node" Name="Price" ID="37f57dea-174a-49dd-966d-cd8da547b055" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="17" Speed="1.0000">
        <Timeline ActionTag="397511332" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="ui/coin_01.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="7" Tween="False">
            <TextureFile Type="Normal" Path="ui/coin_02.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="Normal" Path="ui/coin_03.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="17" Tween="False">
            <TextureFile Type="Normal" Path="ui/coin_04.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="rotate" StartIndex="0" EndIndex="22">
          <RenderColor A="255" R="102" G="205" B="170" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="54" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="coin" ActionTag="397511332" Tag="55" IconVisible="False" LeftMargin="-78.5000" RightMargin="1.5000" TopMargin="-47.0000" BottomMargin="-47.0000" ctype="SpriteObjectData">
            <Size X="77.0000" Y="94.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-40.0000" />
            <Scale ScaleX="0.8000" ScaleY="0.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="ui/coin_01.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="label" ActionTag="-287980934" Tag="101" IconVisible="False" RightMargin="-105.0000" TopMargin="-38.5000" BottomMargin="-38.5000" LabelText="-20" ctype="TextBMFontObjectData">
            <Size X="105.0000" Y="77.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>