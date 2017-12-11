pipeline {
  agent any
  stages {
    stage('GitHub clone') {
      steps {
        git(url: 'https://github.com/ejxct/92-spoons-ai/', branch: 'master')
      }
    }
    stage('Mac Build') {
      steps {
        sh 'mkdir release-mac && clang++ -std=c++11 ai.cpp -o release-mac/ai && zip -r release-mac.zip release-mac'
      }
    }
    stage('GitHub Releases') {
      steps {
        sh '/Users/grant/go/bin/github-release release --draft -u ejxct -r 92-spoons-ai -t $BUILD_NUMBER -s cf0156482bf05038a2fdc811c5d0808e551f8da8 && /Users/grant/go/bin/github-release upload -u ejxct -r 92-spoons-ai -n mac-release.zip --file release-mac.zip -s cf0156482bf05038a2fdc811c5d0808e551f8da8 -t $BUILD_NUMBER'
      }
    }
    stage('After-build') {
      steps {
        warnings(canRunOnFailed: true)
        archiveArtifacts '*'
        emailext(subject: '$DEFAULT_SUBJECT', body: '$DEFAULT_CONTENT', attachLog: true, replyTo: '$DEFAULT_REPLYTO', to: '$DEFAULT_RECIPIENTS')
        cleanWs(cleanWhenAborted: true, cleanWhenFailure: true, cleanWhenNotBuilt: true, cleanWhenSuccess: true, cleanWhenUnstable: true, deleteDirs: true, cleanupMatrixParent: true)
      }
    }
  }
}