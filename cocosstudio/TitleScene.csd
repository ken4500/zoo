<GameProjectFile>
  <PropertyGroup Type="Scene" Name="TitleScene" ID="cda91223-c9d9-4c26-b05d-edc5d26c3654" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="1799" Speed="0.5000">
        <Timeline ActionTag="-347546047" Property="RotationSkew">
          <ScaleFrame FrameIndex="1799" X="360.0000" Y="360.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="37" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="title_back_1" ActionTag="1682281789" Tag="38" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="1.0209" RightMargin="-1.0210" TopMargin="-103.5071" BottomMargin="-108.4930" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="852.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="569.0209" Y="317.5070" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5009" Y="0.4961" />
            <PreSize X="2.0000" Y="2.6625" />
            <FileData Type="Normal" Path="back/title_back.jpg" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="star_effect" ActionTag="324184644" Tag="239" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="568.0000" RightMargin="568.0000" TopMargin="320.0000" BottomMargin="320.0000" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="effect/star.plist" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="glove" ActionTag="-347546047" Tag="113" Rotation="360.0000" RotationSkewX="360.0000" RotationSkewY="360.0000" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="302.9789" RightMargin="305.0211" TopMargin="313.2899" BottomMargin="-197.2899" ctype="SpriteObjectData">
            <Size X="528.0000" Y="524.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="566.9789" Y="64.7101" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4991" Y="0.1011" />
            <PreSize X="0.4648" Y="0.8188" />
            <FileData Type="Normal" Path="back/glove.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="moon_2" ActionTag="1276821145" Tag="263" IconVisible="False" LeftMargin="120.9107" RightMargin="854.0893" TopMargin="127.1718" BottomMargin="352.8282" ctype="SpriteObjectData">
            <Size X="161.0000" Y="160.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="201.4107" Y="432.8282" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1773" Y="0.6763" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ui/moon.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sun_1" ActionTag="-1359428348" Tag="262" IconVisible="False" LeftMargin="725.5352" RightMargin="29.4648" TopMargin="-218.1207" BottomMargin="473.1207" ctype="SpriteObjectData">
            <Size X="381.0000" Y="385.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="916.0352" Y="665.6207" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8064" Y="1.0400" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ui/sun.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Start" ActionTag="-341345126" Tag="39" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="309.2422" RightMargin="326.7578" TopMargin="268.4648" BottomMargin="221.5352" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="30" RightEage="30" TopEage="30" BottomEage="30" Scale9OriginX="30" Scale9OriginY="30" Scale9Width="245" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="500.0000" Y="150.0000" />
            <Children>
              <AbstractNodeData Name="label" ActionTag="566219024" Tag="40" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="189.7420" RightMargin="158.2580" TopMargin="24.5269" BottomMargin="44.4731" LabelText="Start" ctype="TextBMFontObjectData">
                <Size X="152.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="265.7420" Y="84.9731" />
                <Scale ScaleX="1.2000" ScaleY="1.2000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5315" Y="0.5665" />
                <PreSize X="0.4984" Y="0.6045" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="right_arrow_1" ActionTag="-720553403" Tag="167" IconVisible="False" LeftMargin="32.9176" RightMargin="330.0824" TopMargin="31.0464" BottomMargin="31.9536" ctype="SpriteObjectData">
                <Size X="137.0000" Y="87.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="101.4176" Y="75.4536" />
                <Scale ScaleX="0.7000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2028" Y="0.5030" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="book/right_arrow.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="559.2422" Y="296.5352" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4923" Y="0.4633" />
            <PreSize X="0.4401" Y="0.2344" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="book/button02.png" Plist="" />
            <NormalFileData Type="Normal" Path="book/button02.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Language" ActionTag="1003370739" Tag="41" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="278.7422" RightMargin="552.2578" TopMargin="416.0004" BottomMargin="89.9996" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="30" RightEage="30" TopEage="30" BottomEage="30" Scale9OriginX="30" Scale9OriginY="30" Scale9Width="245" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="305.0000" Y="134.0000" />
            <Children>
              <AbstractNodeData Name="label" ActionTag="1730327379" Tag="42" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="6.5000" RightMargin="6.5000" TopMargin="26.5000" BottomMargin="26.5000" LabelText="Language" ctype="TextBMFontObjectData">
                <Size X="292.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="152.5000" Y="67.0000" />
                <Scale ScaleX="0.7000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.9574" Y="0.6045" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="431.2422" Y="156.9996" />
            <Scale ScaleX="0.8000" ScaleY="0.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3796" Y="0.2453" />
            <PreSize X="0.2685" Y="0.2094" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="book/button02.png" Plist="" />
            <NormalFileData Type="Normal" Path="book/button02.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Credit" ActionTag="1815142567" Tag="43" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="534.7422" RightMargin="296.2578" TopMargin="416.0004" BottomMargin="89.9996" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="30" RightEage="30" TopEage="30" BottomEage="30" Scale9OriginX="30" Scale9OriginY="30" Scale9Width="245" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="305.0000" Y="134.0000" />
            <Children>
              <AbstractNodeData Name="label" ActionTag="500014900" Tag="44" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="56.0000" RightMargin="56.0000" TopMargin="26.5000" BottomMargin="26.5000" LabelText="Credit" ctype="TextBMFontObjectData">
                <Size X="193.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="152.5000" Y="67.0000" />
                <Scale ScaleX="0.7000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.6328" Y="0.6045" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="687.2422" Y="156.9996" />
            <Scale ScaleX="0.8000" ScaleY="0.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6050" Y="0.2453" />
            <PreSize X="0.2685" Y="0.2094" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="book/button02.png" Plist="" />
            <NormalFileData Type="Normal" Path="book/button02.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Image_1" ActionTag="368118037" Tag="166" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="97.0000" RightMargin="97.0000" TopMargin="51.2365" BottomMargin="446.7635" Scale9Width="942" Scale9Height="142" ctype="ImageViewObjectData">
            <Size X="942.0000" Y="142.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="517.7635" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.8090" />
            <PreSize X="0.8292" Y="0.2219" />
            <FileData Type="Normal" Path="ui/title_logo.png" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>